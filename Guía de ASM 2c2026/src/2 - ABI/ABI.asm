extern sumar_c
extern restar_c
;########### SECCION DE DATOS
section .data

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS

global alternate_sum_4
global alternate_sum_4_using_c
global alternate_sum_4_using_c_alternative
global alternate_sum_8
global product_2_f
global product_9_f

;########### DEFINICION DE FUNCIONES
; uint32_t alternate_sum_4(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4);
; parametros: 
; x1 --> EDI
; x2 --> ESI
; x3 --> EDX
; x4 --> ECX
alternate_sum_4:
  sub EDI, ESI
  add EDI, EDX
  sub EDI, ECX

  mov EAX, EDI
  ret

; uint32_t alternate_sum_4_using_c(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4);
; parametros: 
; x1 --> EDI
; x2 --> ESI
; x3 --> EDX
; x4 --> ECX
alternate_sum_4_using_c:
  ;prologo
  push RBP ;pila alineada
  mov RBP, RSP ;strack frame armado
  push R12
  push R13	; preservo no volatiles, al ser 2 la pila queda alineada

  mov R12D, EDX ; guardo los parámetros x3 y x4 ya que están en registros volátiles
  mov R13D, ECX ; y tienen que sobrevivir al llamado a función

  call restar_c 
  ;recibe los parámetros por EDI y ESI, de acuerdo a la convención, y resulta que ya tenemos los valores en esos registros
  
  mov EDI, EAX ;tomamos el resultado del llamado anterior y lo pasamos como primer parámetro
  mov ESI, R12D
  call sumar_c

  mov EDI, EAX
  mov ESI, R13D
  call restar_c

  ;el resultado final ya está en EAX, así que no hay que hacer más nada

  ;epilogo
  pop R13 ;restauramos los registros no volátiles
  pop R12
  pop RBP ;pila desalineada, RBP restaurado, RSP apuntando a la dirección de retorno
  ret


alternate_sum_4_using_c_alternative:
  ;prologo
  push RBP ;pila alineada
  mov RBP, RSP ;strack frame armado
  sub RSP, 16 ; muevo el tope de la pila 8 bytes para guardar x4, y 8 bytes para que quede alineada

  mov [RBP-8], RCX ; guardo x4 en la pila

  push RDX  ;preservo x3 en la pila, desalineandola
  sub RSP, 8 ;alineo
  call restar_c 
  add RSP, 8 ;restauro tope
  pop RDX ;recupero x3
  
  mov EDI, EAX
  mov ESI, EDX
  call sumar_c

  mov EDI, EAX
  mov ESI, [RBP - 8] ;leo x4 de la pila
  call restar_c

  ;el resultado final ya está en EAX, así que no hay que hacer más nada

  ;epilogo
  add RSP, 16 ;restauro tope de pila
  pop RBP ;pila desalineada, RBP restaurado, RSP apuntando a la dirección de retorno
  ret


; uint32_t alternate_sum_8(uint32_t x1, uint32_t x2, uint32_t x3, uint32_t x4, uint32_t x5, uint32_t x6, uint32_t x7, uint32_t x8);
; registros y pila: x1[EDI], x2[ESI], x3[EDX], x4[ECX], x5[R8], x6[R9], x7[pila], x8[pila]
alternate_sum_8:
	;prologo
  push RBP ;;alineo pila
  mov RBP, RSP; ;;sumo al stack frame
  mov R10D, [RSP+16] ;;x7
  mov R11D, [RSP+24] ;;x8
	sub EDI, ESI
  add EDI, EDX
  sub EDI, ECX
  add EDI, R8D
  sub EDI, R9D
  add EDI, R10D
  sub EDI, R11D
  MOV EAX, EDI
	;epilogo
  pop RBP
	ret


; SUGERENCIA: investigar uso de instrucciones para convertir enteros a floats y viceversa
;void product_2_f(uint32_t * destination, uint32_t x1, float f1);
;registros: destination[EDI], x1[ESI], f1[XMM0]
product_2_f:

 cvtsi2ss XMM1, ESI ;;x1 a float
 MULSS XMM1, XMM0 
 CVTtSS2SI ESI, XMM1 ;; float a entero
 MOV [RDI],ESI ;; la direccion es de 64 bits, pero apunta a un uint32. Osea uso RDI y no EDI para ir a la posi de memoria
 ret


;extern void product_9_f(double * destination
;, uint32_t x1, float f1, uint32_t x2, float f2, uint32_t x3, float f3, uint32_t x4, float f4
;, uint32_t x5, float f5, uint32_t x6, float f6, uint32_t x7, float f7, uint32_t x8, float f8
;, uint32_t x9, float f9);
;registros y pila: destination[RDI], x1[ESI], f1[XMM0], x2[EDX], f2[XMM1], x3[ECX], f3[XMM2], x4[R8], f4[XMM3]
;	, x5[R9], f5[XMM4], x6[RBP+16], f6[XMM5], x7[RBP+24], f7[XMM6], x8[RBP+32], f8[XMM7],
;	, x9[RBP+40], f9[RBP+40]
product_9_f:
	;prologo
	push rbp
	mov rbp, rsp

  ;;guardar en registros scratch enteros de la pila y float de la pila
  MOV R10D,[RBP+16]
  MOV R11D,[RBP+24]
  MOVSS XMM8,[RBP+48]
  push R12
  PUSH R13
  MOV R12D, [RBP+32]
  MOV R13D, [RBP+40]

	;convertimos los flotantes de cada registro xmm en doubles
	CVTSS2SD XMM0,XMM0;;float a double
  CVTSS2SD XMM1,XMM1
  CVTSS2SD XMM2,XMM2
  CVTSS2SD XMM3,XMM3
  CVTSS2SD XMM4,XMM4
  CVTSS2SD XMM5,XMM5
  CVTSS2SD XMM6,XMM6
  CVTSS2SD XMM7,XMM7
  CVTSS2SD XMM8,XMM8


	;multiplicamos los doubles en xmm0 <- xmm0 * xmm1, xmmo * xmm2 , ...
	MULSD XMM0,XMM1
  MULSD XMM0,XMM2
  MULSD XMM0,XMM3
  MULSD XMM0,XMM4
  MULSD XMM0,XMM5
  MULSD XMM0,XMM6
  MULSD XMM0,XMM7
  MULSD XMM0,XMM8

	; convertimos los enteros en doubles y los multiplicamos por xmm0.
	CVTSI2SD XMM9, ESI
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, EDX
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, ECX
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, R8D
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, R9D
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, R10D
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, R11D
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, R12D
  MULSD XMM0,XMM9
	CVTSI2SD XMM9, R13D
  MULSD XMM0,XMM9

  MOVSD [RDI], XMM0

  POP R13
  POP R12
	; epilogo
	pop rbp
	ret

