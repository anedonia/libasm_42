section .text
global ft_strcpy

ft_strcpy: 
	xor rax, rax
	xor rbx, rbx
	
	cmp byte [rsi], 0
	je .done
	jmp .loop

.loop: 
	mov bl, byte [rsi + rax]
	mov byte [rdi + rax], bl
	cmp bl, 0
	je .done
	inc rax
	jmp .loop
	

.done:
	mov rax, rdi
	ret 
