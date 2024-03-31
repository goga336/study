%include "lib.asm"
section .data
	ib db "Enter M, A, K: ", 0
	ia db "Your result: ", 0

 section .bss
	outbuf resb 10
	lenout equ $-outbuf
	M resw 1
	A resw 1
	K resw 1

	inbuf resb 10
	lenIn equ $-inbuf

	msgB resb 15
	lenMsgB equ $-msgB


	msgA resb 13
	lenMsgA equ $-msgA

section .text
global _start
_start:	
	 jmp InputM

InputM:
    ;; вывовдим сообщение ib
    mov eax, 4
    mov ebx, 1
    mov ecx, ib
    mov edx, lenMsgB
    int 0x80

    ;; считываем введеное число
    mov eax, 3
    mov ebx, 0
    mov ecx, inbuf
    mov edx, 10
    int 0x80

    ;; передаем параметры в функцию
    mov esi, inbuf
    call StrToInt
    cmp EBX, 0
    mov [M], ax
    jmp InputA

InputA:
    ;; считываем введеное число
    mov eax, 3
    mov ebx, 0
    mov ecx, inbuf
    mov edx, 10
    int 0x80

    ;;передаем параметры в функцию 
    mov esi, inbuf
    call StrToInt
    cmp EBX, 0
    mov [A], ax
   jmp InputK

InputK:
    ;; считываем введеное число
    mov eax, 3
    mov ebx, 0
    mov ecx, inbuf
    mov edx, 10
    int 0x80

     ;;передаем параметры в функцию
    mov esi, inbuf
    call StrToInt
    cmp EBX, 0
    mov [K], ax
    jmp Calc

Calc:
	mov ax, [M]
	cmp ax, [A]
	jle met
	sub ax, 5
	mov esi, outbuf
	cwde
	call IntToStr
	;; mov eax, 4
	;; mov ebx, 1
	;; mov ecx, outbuf
	;; mov edx, eax
	int 0x80

	jmp exit
met:
	mov dx, [A]
	imul ax, dx
	mov cx, [K]
	cwd
	idiv cx
	mov esi, outbuf
	cwde
	call IntToStr
	jmp exit

exit:
	mov eax, 4
	mov ebx, 1
	mov ecx, ia
	mov edx, lenMsgA
	int 0x80

	;; выводим результат
	mov eax, 4
	mov ebx, 1
	mov ecx, outbuf
	mov edx, eax
	int 0x80

	mov eax, 1
	xor ebx, ebx
	int 0x80
