extern __errno_location
section .text 

global ft_write

ft_write:
	; rdi = fd, rsi = *void buf, rdx = int count
	xor rax, rax
	mov rax, 1
	syscall
	cmp rax, 0
	jl .error_exit
	ret

.error_exit:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
    ret