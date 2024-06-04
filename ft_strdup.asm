section .text: 
extern malloc
extern ft_strlen
extern ft_strcpy
global ft_strdup: 
	; rdi pointeur sur src 
	mov rbx, rdi ; sve the string 
	mov rdi, rbx ; move the string to rdi to call strlen
	call ft_strlen

	inc rax ; le null term
	mov rdi, rax ; put the size to malloc in rdi 
	call malloc	
	test rax, rax
	jz .fail ; if malloc failed ret 0
	
	mov rdi, rax ; prep the args to call strcpy
	mov rsi, rbx
	call ft_strcpy
	jmp .done

.fail 
	xor rax, rax
	ret

.done 
	ret
	


