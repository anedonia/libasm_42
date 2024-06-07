section .text 

global ft_read

ft_read:
	; rdi = fd, rsi = *void buf, rdx = int count
	xor rax, rax
	mov rax, 0
	syscall
	cmp rax, 0
	jl .error_exit
	ret

.error_exit:
	mov rax, -1
	ret