global ft_strcpy
section .text

ft_strcpy:
	push rbp ; prologue
	mov rbp, rsp ; prologue
	xor rax, rax ; init rax as char_source
	xor rcx, rcx ; init rcx as counter
	jmp loop ; start loop

loop:
	mov al, byte[rsi + rcx] ; store char_source in rax
	mov byte[rdi + rcx], al ; copy char_source in dest
	cmp al, 0 ; if source ends (null char)
	je exit ; end the loop
	inc rcx ; else increment the counter
	jmp loop ; and continue looping

exit:
	mov rax, rdi ; store the dest pointer as return value
	pop rbp ; epilogue
	ret ; and return
