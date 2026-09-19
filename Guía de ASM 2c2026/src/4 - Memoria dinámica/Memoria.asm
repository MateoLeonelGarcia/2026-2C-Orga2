extern malloc
extern free
extern fprintf

section .data

section .text

global strCmp
global strClone
global strDelete
global strPrint
global strLen

; ** String **

; int32_t strCmp(char* a [RDI], char* b [RSI])
strCmp:
	push rbp
	mov rbp,rsp

;     while (*a != '\0' && *a == *b)
.loop: ;;r10 = *a y r11 = *b
	mov  r10B, byte [rdi] ;;chequear si funciona el B
	cmp  r10B,0x0
	je .finloop
	mov  r11B, byte [rsi]
	cmp r10b,r11b
	jne .finloop
;     {
;         a++;
;         b++;
;     }
	inc rdi
	inc rsi
	jmp  .loop
.finloop:
;     unsigned char ca = (unsigned char)*a;
;     unsigned char cb = (unsigned char)*b; 
	mov r10b, byte [rdi]
	mov r11b, byte [rsi]
	cmp r10b,r11b

;     if (ca == cb)
	je .iguales
;     if (ca < cb)
	jl .amenorb
;     if (ca < cb)
	jg .amayorb
.iguales:
	mov eax,0
	jmp .fin
.amenorb:
	mov eax, 1
	jmp .fin
.amayorb:
	mov eax, -1;

.fin:
	pop rbp
	ret

; char* strClone(char* a)
strClone:
	push rbp
	mov rbp,rsp
;; char *strClone(char *a [RDI])
; // {
	push r12 ;;guardo rdi en la pila y de paso la alineo
	
	push rdi ;; para dejar la pila alineada

; //     uint32_t strlen = strLen(a);
	call strLen ;;eax = len(a)
	inc eax
	mov r12D, eax ;;r11 = strlen(a)
	 
	mov edi, eax ;;pongo rdi = size(a) + 1 en bytes es lo mismo que el string..
; //     char *clone = malloc((strlen + 1)* sizeof(char));
	call malloc ;;en rax tengo el char* a mi clone
	pop rdi
; //     char *dst = clone;
	mov r10, rax
	;; //     for (size_t i = 0; i <= strlen; i++)

.loop:
	cmp r12, 0x0
	je .finloop
; //         *dst = *a;
	mov r8b, byte [rdi]
	mov byte [r10], r8b
; //         dst++;
	inc r10
; //         a++;
	inc rdi
	dec r12
	jmp .loop
; //     return clone;
; // }
.finloop:
	
	pop r12
	pop rbp
	ret

; void strDelete(char* a [RDI])
strDelete:
	push rbp
	mov rbp, rsp
	call free
	pop rbp
	ret

; void strPrint(char* a, FILE* pFile)
strPrint:
	ret

; uint32_t strLen(char* a [RDI])
strLen:
	push rbp
	mov rbp,rsp
; uint32_t len = 0;
	xor r8,r8
.loop: 
	mov r10b, byte [rdi]
;     while (*a != '\0')
	cmp r10b,0x0
	je .finloop
	    ;;len++;    
	inc r8
	inc rdi
	jmp .loop
.finloop:
	mov eax, r8d
;     return len;
	pop rbp
	ret


