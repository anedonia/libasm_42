section .text

global ft_strcmp

ft_strcmp:
	; rdi = s1 rsi = s2
	xor rax, rax
	xor rbx, rbx
	xor rcx, rcx
	jmp .loop

.loop:
	mov cl, [rdi + rax]
	mov bl, [rsi + rax]
	cmp bl, cl
	jne .done
	test cl, cl
	jz .equal
	inc rax
	jmp .loop


.done:
	sub cl, bl
	movsx rax, cl
	ret

.equal: 
	xor rax, rax 
	ret