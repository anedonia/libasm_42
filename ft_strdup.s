section .text
global ft_strdup
extern malloc
extern ft_strlen
extern ft_strcpy

ft_strdup: 
	; rdi pointeur sur src 
	mov rbx, rdi ; sve the string 
	push rbx
	call ft_strlen

	inc rax ; le null term
	mov rdi, rax ; put the size to malloc in rdi 
	call malloc  wrt ..plt
	test rax, rax
	jz .fail ; if malloc failed ret 0
	
	mov rdi, rax ; prep the args to call strcpy
	pop rbx
	mov rsi, rbx
	call ft_strcpy
	jmp .done

.fail: 
	xor rax, rax
	ret

.done:
	ret
	


