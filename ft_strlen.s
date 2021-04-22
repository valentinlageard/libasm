global ft_strlen
section .text

ft_strlen:
	xor rax, rax ; init rax as counter
	jmp loop ; start looping

loop:
	cmp byte [rdi + rax], 0 ; if char is null char
	je exit ; quit loop
	inc rax ; else increment counter
	jmp loop ; and continue looping

exit:
	ret ; return the counter stored in rax
