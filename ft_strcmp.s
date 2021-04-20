global ft_strcmp
section .text

ft_strcmp:
	mov rax, 0
	mov rbx, 0
	mov rcx, 0
	jmp loop

loop:
	mov al, byte[rdi + rcx]
	mov bl, byte[rsi + rcx]
	cmp al, 0
	je exit
	cmp al, bl
	jne exit
	inc rcx
	jmp loop

exit:
	sub rax, rbx
	ret
