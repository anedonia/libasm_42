section .text: 
global ft_strcpy

ft_strcpy: ; on check que source n'est pas vide puis on copy chaque bit de src vers dest 
	xor rax, rax
	; dest = rdi, src = rsi
	cmp [rsi], 0
	je .done
	jmp .loop

.loop: 
	mov al, [rsi + rax]
	mov [rdi + rax], al
	cmp al, 0
	je .done
	inc rax
	jmp .loop
	

.done:
	mov rax, rdi
	ret 
