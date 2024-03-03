%include "lib.asm"
 
section .data
    ib db "Enter B: ", 0
    ic db "Enter C: ", 0
    id db "Enter D: ", 0
    ia db "Your result: ", 0

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
    
    A resw 1
    B resd 1
    C resd 1
    D resd 1

section .text
global _start
_start:
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
    mov [B], ax

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
    mov [C], ax

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
    mov [D], ax

    ;;записываем значения переменных в регистры
    mov bx, [B]
    mov ax, [C]
    mov dx, [D]

    xor ecx, ecx
    mov cx, ax
    sub cx, 5
    imul cx, dx
    add cx, bx
    mov ax, cx
    imul bx, bx
    add bx, 1

    xor edx, edx
    div bx
    shl edx, 16
    or eax, edx
    mov [A], ax

    ;;конвертирум  из A в строку
    mov esi, outbuf
    mov ax, [A]
    call IntToStr

    mov eax, 4
    mov ebx, 1
    mov ecx, ia
    mov edx, lenMsgA
    int 0x80
    ;; выводим результат
    mov eax, 4
    mov ebx, 1
    mov ecx, outbuf
    mov edx, lenout
    int 0x80

    mov eax, 1
    xor ebx, ebx
    int 0x80

