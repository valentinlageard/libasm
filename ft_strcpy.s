global ft_strcpy
section .text

ft_strcpy:
	mov rax, 0
	mov rcx, 0
	jmp loop

loop:
	mov al, byte[rsi + rcx]
	mov byte[rdi + rcx], al
	cmp al, 0
	je exit
	inc rcx
	jmp loop

exit:
	mov rax, rdi
	ret
