%include "lib.asm"
 
section .data
    ib db "Enter B: ", 10
    ic db "Enter C: ", 10
    id db "Enter D: ", 10
    ia db "Your result: ", 10

section .bss
    msgB resb 10
    lenMsgB equ $-msgB
    
    msgC resb 10
    lenMsgC equ $-msgC
    
    msgD resb 10
    lenMsgD equ $-msgD

    msgA resb 13
    lenMsgA equ $-msgA

    inbuf resb 10
    lenIn equ $-inbuf

    outbuf resb 10
    lenout equ $-outbuf
    
    A resd 1
    B resd 1
    C resd 1
    D resd 1

section .text
global _start
_start:
   jmp InputB

InputB:
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
    mov [B], eax
    jmp InputC

InputC:
    ;; вывовдим сообщение ic
    mov eax, 4
    mov ebx, 1
    mov ecx, ic
    mov edx, lenMsgC
    int 0x80

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
    mov [C], eax
   jmp InputD

InputD:
    ;; вывовдим сообщение id
    mov eax, 4
    mov ebx, 1
    mov ecx, id
    mov edx, lenMsgD
    int 0x80

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
    mov [D], eax
    jmp Calc

Calc:
	mov ebx, [B]
	
	mov eax, [C]		
	mov edx, [D]

	xor ecx, ecx
	mov ecx, [C]
	sub ecx, 5
	mov eax, ecx
	

	imul edx
	add eax, ebx
	xor ecx, ecx
	mov ecx, eax
	mov eax, ebx
	imul ebx
	add eax, 1
	mov ebx, eax
mov eax, ecx
	cdq
    idiv ebx
    

    mov [A], eax
    jmp Output


Output:	
    mov eax, 4
    mov ebx, 1
    mov ecx, ia
    mov edx, lenMsgA
    int 0x80

    ;;конвертирум  из A в строку
    mov esi, outbuf
	cwde
    mov eax, [A]
    call IntToStr


    ;; выводим результат
    mov eax, 4
    mov ebx, 1
    mov ecx, outbuf
    mov edx, lenout
    int 0x80
    jmp Exit

Exit:	
    mov eax, 1
    xor ebx, ebx
    int 0x80

