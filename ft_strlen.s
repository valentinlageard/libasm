	global ft_strlen
	section .text

ft_strlen:
	mov rax, 0
	jmp loop

loop:
	cmp byte [rdi + rax], 0
	je exit
	inc rax
	jmp loop

exit:
	ret
