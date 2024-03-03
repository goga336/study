 	section .data ; сегмент инициализированных переменных
ExitMsg db "Press Enter to Exit",10 ; выводимое сообщение
lenExit equ $-ExitMsg

numA dw 25
num_b dd -35
nameru db 'Георгий', 0
name db 'George', 0

num1 db 37
num1_1 db 0b100101

num2 dw 9472
num2_2 dw 0o22400

F1 dw 65534
F2 dd 65535

A dw -30
B dw 21
val1 db 255
chart dw 256
lue3 dw -128
v5 db 10h
db 100101B
beta db 23,23h,0ch
sdk db "Hello",10
min dw -32767
ar dd 12345678h
valar times 5 db 8
	section .bss ; сегмент неинициализированных переменных
InBuf resb 10 ; буфер для вводимой строки
lenIn equ $-InBuf
X resd 1 ; переменная для результата
alu resw 10
f1 resb 5
section .text ; сегмент кода
global _start
_start:
; write
	mov eax, 4 ; системная функция 4 (write)
	mov ebx, 1 ; дескриптор файла stdout=1
	mov ecx, ExitMsg ; адрес выводимой строки
	mov edx, lenExit ; длина выводимой строки
	int 80h ; вызов системной функции
	
	mov eax, [A]
	add eax, 5 
	sub eax, [B] 
	mov [X], eax 

	add [F1],1
	add [F2],1
	; read
	mov eax, 3 ; системная функция 3 (read)
	mov ebx, 0 ; дескриптор файла stdin=0
	mov ecx, InBuf ; адрес буфера ввода
	mov edx, lenIn ; размер буфера
	int 80h ; вызов системной функции
				; exit
	mov eax, 1 ; системная функция 1 (exit)
	xor ebx, ebx ; код возврата 0
	int 80h
