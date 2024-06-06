section .text
global ft_strcpy

ft_strcpy: ; on check que source n'est pas vide puis on copy chaque bit de src vers dest 
	xor rax, rax
	xor rbx, rbx
	; dest = rdi, src = rsi
	cmp byte [rsi], 0
	je .done
	jmp .loop

.loop: 
	mov bl, [rsi + rax]
	mov [rdi + rax], bl
	cmp bl, 0
	je .done
	inc rax
	jmp .loop
	

.done:
	mov rax, rdi
	ret 
