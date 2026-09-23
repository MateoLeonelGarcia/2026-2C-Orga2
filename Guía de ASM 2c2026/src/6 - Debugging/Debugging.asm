extern strcpy
extern malloc
extern free

section .rodata
; Acá se pueden poner todas las máscaras y datos que necesiten para el ejercicio

section .text
; Marca un ejercicio como aún no completado (esto hace que no corran sus tests)
FALSE EQU 0
; Marca un ejercicio como hecho
TRUE  EQU 1

ITEM_OFFSET_NOMBRE EQU 0;;9
ITEM_OFFSET_ID EQU 12;;16
ITEM_OFFSET_CANTIDAD EQU 16;;24

POINTER_SIZE EQU 8
UINT32_SIZE EQU 4

; Marcar el ejercicio como hecho (`true`) o pendiente (`false`).

global EJERCICIO_1_HECHO
EJERCICIO_1_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

global EJERCICIO_2_HECHO
EJERCICIO_2_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

global EJERCICIO_3_HECHO
EJERCICIO_3_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

global EJERCICIO_4_HECHO
EJERCICIO_4_HECHO: db TRUE ; Cambiar por `TRUE` para correr los tests.

global ejercicio1
ejercicio1:
	add rdi, rcx
	add rdi, rdx
    add rdi, rsi
    add rdi, r8
	mov rax, rdi
	ret

global ejercicio2
ejercicio2:
	push rbp
	mov rbp, rsp
	mov [rdi+ITEM_OFFSET_ID], esi
	mov [rdi+ITEM_OFFSET_CANTIDAD], edx
	mov esi, ecx
	call strcpy
	pop rbp
	ret


global ejercicio3
ejercicio3:
	push rbp
	mov rbp, rsp

	cmp esi, 0
	je .vacio
	
	mov rcx, rdi ; array
	mov r8, 0 ; sumatoria
	mov r9, 0 ; i
	mov r10, rsi ;; tamanio original del arreglo

	.loop:
	mov rdi, r8
	mov esi, [rcx + r9*4]
	push r10
	push rdx
	push rcx
	push r9
	push r8
	sub rsp,8

	call rdx

	add rsp,8
	pop r8
	pop r9
	pop rcx
	pop rdx
	pop r10

	add r8, rax
	inc r9
	cmp r9, r10
	jl .loop

	mov rax, r8
	pop rbp
	ret

	.vacio:
	mov rax, 64
	pop rbp
	ret

global ejercicio4
ejercicio4:
	push rbp
	mov rbp,rsp

	mov r12, rdi
	mov r13d, esi
	mov r14d, edx

	xor rdi, rdi
	mov eax, UINT32_SIZE
	mul esi
	mov edi, eax

	call malloc
	mov r15, rax
	
	xor rbx, rbx
	.loop:
	
	cmp ebx, r13d
	je .end

	mov r8, [r12+rbx*POINTER_SIZE]
	mov r9d, [r8]
	mov eax, r14d
	mul r9d
	mov [r15+rbx*UINT32_SIZE], eax
	
	mov rdi, r8 
	call free
	mov [r12 + rbx*POINTER_SIZE], dword 0x0

	inc rbx
	jmp .loop

	.end:
	mov rax, r15
	pop rbp
	ret
