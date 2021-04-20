	global ft_strlen
	section .text

ft_strlen:
	mov rax, 0
	jmp count

count:
	cmp byte [rdi + rax], 0
	je exit
	inc rax
	jmp count

exit:
	ret
