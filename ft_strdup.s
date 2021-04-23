global ft_strdup
extern __errno_location
extern ft_strlen
extern ft_strcpy
extern malloc
section .text

ft_strdup:
	push rbp ; prologue
	mov rbp, rsp ; prologue
	push rdi ; save source address in stack
	call ft_strlen ; get the string length
	inc rax ; add 1 for the null char
	mov rdi, rax ; store the string length as first arg
	call malloc ; call malloc
	cmp rax, 0 ; if null is returned
	je error ; then go to error management
	; else
	mov rdi, rax ; store the dest address as first arg
	pop rsi ; restore the source addr as 2nd arg from stack
	call ft_strcpy ; copy source to dest
	pop rbp ; epilogue
	ret ; return dest

error:
	neg rax ; invert the error code
	mov rcx, rax ; store the error code in rcx
	call __errno_location ; get errno address
	mov [rax], rcx ; store the error code in errno address
	mov rax, 0 ; return value is NULL in case of error
	pop rdi ; restore address (just for epilogue)
	pop rbp ; epilogue
	ret
