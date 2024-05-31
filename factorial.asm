;To count the factorial of a number

section .data
	form_msg db "Enter a number!.", 10, 0
	form_p db "The factorial of %d is: %d.", 10, 0
	form_s db "%d", 0

section .bss
	num resd 1
	extern printf
	extern scanf
section .text
	global main
	main:
	push rbp
	mov rbp, rsp

	mov rdi, form_msg
	mov rax, 0
	call printf

	mov rdi, form_s
	mov rsi, num
	mov rax, 0
	call scanf

	movsx rsi, dword[num]
	mov rax, 1

	cmp rsi, 0
	jl Low
	
	L:
	cmp rsi, 0
	je Print
	mul rsi
	dec rsi
	jmp L

	Low:
	mov rax, -1

	Print:
	mov rdi, form_p
	movsx rsi, dword[num]
	mov rdx, rax
	mov rax, 0
	call printf

	mov rsp, rbp
	pop rbp
	ret

; you can compile this code with - "nasm -f elf64 factorial.asm"
; then you can link this code with GNU Compiler Collection - "gcc -o factorial factorial.o -no-pie"
	jmp L

