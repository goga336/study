%include "lib.asm"
section .data
 enterMsg db "Enter Array by lines:",10
 lenEnterMsg equ $-enterMsg
 outPut db "Your result: ", 10
lenOutMsg equ $-outPut
 	;; mas dd -1,-2,-3,-4,5
	;;     dd -115,-16,-7,8,9
	;;     dd 10,116,0,8,9
       	;;     dd 100,-100,7,8,9
	;;     dd 5,6,7,8,9 ;;answer: 35
	    count dd 0

section .bss
	mas resw 25
	inbuf resw 10
	lenIn equ $-inbuf

	outbuf resb 10
	lenout equ $-outbuf
	result resd 1
section .text
global _start	
_start:
				; выводим сообщение о необходимости ввода
	mov eax, 4 ; системная функция 4 (write)
	mov ebx, 1 ; дескриптор файла stdout=1
	mov ecx, enterMsg ; адрес выводимой строки
	mov edx, lenEnterMsg ; длина выводимой строки
	int 80h ; вызов системной функции
	
	mov ECX, 0 ; счетчик для ввода чисел
input:
	push ECX ; сохраняем значение счетчика цикла в стек
	mov eax, 3 ; системная функция 3 (read)
	mov ebx, 0 ; дескриптор файла stdin=0
	mov ecx, inbuf ; адрес буфера ввода
	mov edx, lenIn ; размер буфера
	int 80h ; вызов системной функции
	
				; передаем значние в функцию
	mov esi,inbuf ; адрес введенной строки
	call StrToInt
	cmp EBX, 0 ; проверка кода ошибки
	
	pop ECX ; возвращаем значение счетчика цикла из стека
	mov [mas + ECX*4], eax ; запись числа в память   
	inc ECX ; увеличиваем счетчик
	cmp ECX, 25 ; ввели меньше 24 чисел? тогда продолжаем
	jne input


	mov edi, 4		;записываем в регистр кол-во элементов в строке, до которой будем считать сумму
	mov ecx, 4 		;записываем в регистр кол-во столбцов
	mov edx, 0		;здесь будем подсчитывать сумму элементов
	mov ebx, 0		;счетчик элементов
	mov eax, 1		;сюда будем записывать кол-во элементов через которые будем перескакивать
cycle:	
	push ecx		;закинули в стек ecx
	mov ecx, edi		;записали в регистр ecx значение кол-ва элементов до которых будем считать
	dec edi			;каждый раз уменьшаем количество элементов на 1
	push eax		;закинем в стек значение региста eax
.cycle:
	mov eax, [mas + ebx*4]	;запишем в eax значение текущего элемента
	inc ebx			;прибавляем 1 для подсчета следующего элемента
	cmp eax, 0		;сравниваем текущее значение с 0
	jl .men		;если меньше 0, то переходим к след элементу без добавления текущего элемента к сумме
	add edx, eax 		;добавляем значение текущего элемента в общуюю сумму
.men:
	loop .cycle		;возвращаемся на метку по суммированию строк
	pop eax			;возвращаем кол-во элементов через которые будем перескакивать
	add ebx, eax		;суммируем
	inc eax			;инкрементируем  кол-во элементов через которые будем перескакивать
	pop ecx			;возвращаем кол-во столбцов
	loop cycle		;возвращаемся к циклу
	jmp print

print:	
	mov [result], edx 	;переписываем значение регистра edx в переменную
	mov eax, [result]
	mov esi, outbuf
	cwde
	call IntToStr
	;; выводим результат на экран
	mov eax, 4
	mov ebx, 1
	mov ecx, outPut
	mov edx, lenOutMsg
	int 0x80

	mov eax, 4
	mov ebx, 1
	mov ecx, outbuf
	mov edx, eax
	int 0x80


	mov eax, 1
	xor ebx, ebx
	int 0x80

	
