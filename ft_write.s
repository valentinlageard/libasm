global ft_write
extern __errno_location
section .text

ft_write:
	mov rax, 1 ; select the write syscall
	; (rdi, rsi and rdx already contains the arguments)
	syscall
	cmp rax, 0 ; if there was an error
	jl error ; jump to error management
	ret ; else return rax
	; (which contains the number of written bytes)

error:
	neg rax ; invert the error code
	mov rcx, rax ; store the error code in rcx
	call __errno_location ; get errno address
	mov [rax], rcx ; store the error code in errno address
	mov rax, -1 ; return value is -1 in case of error
	ret
