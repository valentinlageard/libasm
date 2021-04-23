global ft_strcmp
section .text

ft_strcmp:
	push rbp ; prologue
	mov rbp, rsp ; prologue
	xor rax, rax ; init rax as char1
	push rbx ; save rbx (must be preserved)
	xor rbx, rbx ; init rbx as char2
	xor rcx, rcx ; init rcx as a counter
	jmp loop ; start loop

loop:
	mov al, byte[rdi + rcx] ; store char1 in rax
	mov bl, byte[rsi + rcx] ; store char2 in rbx
	cmp al, 0 ; if s1 ends (null char)
	je exit ; end the loop
	cmp al, bl ; if char1 is different from char2
	jne exit ; end the loop
	inc rcx ; else increment the counter
	jmp loop ; and loop

exit:
	sub rax, rbx ; in place substract rbx from rax
	pop rbx ; restore rbx
	pop rbp ; epilogue
	ret ; return the substraction stored in rax
