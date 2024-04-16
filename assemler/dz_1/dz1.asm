%include "lib.asm"

section .data
	 i db 65
	resul times 22 db ' '
	counter dd 0
	msg db 'Enter number : ', 10
	lenmsg equ $-msg
	msge db 'Enter number <=30', 10
	lenmsge equ $-msg
section .bss
	buffer resb 1
	num resw 1
	lenIn equ $-num
section .text
global _start

_start:
vvod:	
	mov EAX, 4
	mov EBX, 1
	mov ECX, msg
	mov EDX, lenmsg
	int 80h
	
	mov EAX, 3
	mov EBX, 0
	mov ECX, num
	mov EDX, 10
	int 80h
	mov esi, num
	call StrToInt
	cmp EBX, 0
	mov [num], eax
cravn:	

	mov eax, 30
	mov ecx, [num]
	cmp eax, ecx
	jl exit
	jmp vich
exit:	
	mov EAX, 4
	mov EBX, 1
	mov ECX, msge
	mov EDX, lenmsge
	int 80h
	jmp ex
vich:	
	mov ecx, [num]
	mov ebx, 0


metk:	
	push ecx
	mov ecx, [counter]
	mov al, [i]
	lea edi, [resul + ebx]
	inc ebx
	inc edx
	stosb
	cmp ecx, edx
	jl high           
	jge low 
high:	
	mov edx, 0
	add ecx, 1
	inc al
	mov [i], al
	mov [counter], ecx
	jmp cont
low:	
	jmp cont
cont:	
	pop ecx
	loop metk



	mov EAX, 4
	mov EBX, 1
	mov ECX, resul
	mov EDX, [num]
	int 80h
	mov EAX, 4
	mov EBX, 1
	mov BYTE[buffer], 10
	mov ECX, buffer
	mov EDX, 1
	int 80h

ex:	
	mov EAX, 1
	int 80h
