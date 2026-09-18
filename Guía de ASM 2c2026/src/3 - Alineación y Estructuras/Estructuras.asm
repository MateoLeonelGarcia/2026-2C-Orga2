

;########### ESTOS SON LOS OFFSETS Y TAMAÑO DE LOS STRUCTS
; Completar las definiciones (serán revisadas por ABI enforcer):
NODO_OFFSET_NEXT EQU 0;;12
NODO_OFFSET_CATEGORIA EQU 8;;1
NODO_OFFSET_ARREGLO EQU 16;;8
NODO_OFFSET_LONGITUD EQU 24;;4
NODO_SIZE EQU 32;8
PACKED_NODO_OFFSET_NEXT EQU 0;;8
PACKED_NODO_OFFSET_CATEGORIA EQU 8;;8
PACKED_NODO_OFFSET_ARREGLO EQU 9;;8
PACKED_NODO_OFFSET_LONGITUD EQU 17;;8
PACKED_NODO_SIZE EQU 21;;8
LISTA_OFFSET_HEAD EQU 0;;8
LISTA_SIZE EQU 8
PACKED_LISTA_OFFSET_HEAD EQU 0;;8
PACKED_LISTA_SIZE EQU 8

;########### SECCION DE DATOS
section .data

;########### SECCION DE TEXTO (PROGRAMA)
section .text

;########### LISTA DE FUNCIONES EXPORTADAS
global cantidad_total_de_elementos
global cantidad_total_de_elementos_packed

;########### DEFINICION DE FUNCIONES
;extern uint32_t cantidad_total_de_elementos(lista_t* lista);
;registros: lista[RDI] el primer valor es un puntero a un nodo_t
cantidad_total_de_elementos:
	push rbp
	mov rbp, rsp
	; int i = 0;
	xor rcx,rcx  ;; mi contador rcx=0
	xor r8,r8
	xor r9,r9 ;; sum =0
    ; nodo_t *nodotmp = lista.head;
	mov r10, [rdi] ;;estaria agarrando el puntero al nodo head?
; while (nodotmp != NULL)
    ; {
	
.loop:
	cmp r10, 0x0 ;;null seria la direccion 0x0000 0000 0000 0000
	je .finloop
;     i++;
	inc rcx
	;; sum += nodo.longitud
	mov r9, [r10 + NODO_OFFSET_LONGITUD]
	add r8,r9
	 ;     nodotmp = nodotmp->next;
	mov r11,[r10]
	mov r10,r11
	jmp .loop
.finloop:


    ; return i;
	mov rax,r8
	pop rbp
	ret

;extern uint32_t cantidad_total_de_elementos_packed(packed_lista_t* lista);
;registros: lista[?]
cantidad_total_de_elementos_packed:
	push rbp
	mov rbp, rsp
	; int i = 0;
	xor rcx,rcx  ;; mi contador rcx=0
	xor r8,r8
	xor r9,r9 ;; sum =0
    ; nodo_t *nodotmp = lista.head;
	mov r10, [rdi] ;;estaria agarrando el puntero al nodo head?
; while (nodotmp != NULL)
    ; {
	
.loop:
	cmp r10, 0x0 ;;null seria la direccion 0x0000 0000 0000 0000
	je .finloop
;     i++;
	inc rcx
	;; sum += nodo.longitud
	mov r9D, [r10 + PACKED_NODO_OFFSET_LONGITUD]
	add r8D,r9D
	 ;     nodotmp = nodotmp->next;
	mov r11,[r10]
	mov r10,r11
	jmp .loop
.finloop:


    ; return i;
	mov eax,r8d
	pop rbp
	ret

