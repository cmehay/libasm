section .text

;int   isalnum(int rdi);
global ft_isalnum
extern ft_isalpha
extern ft_isdigit

ft_isalnum:
	call    ft_isalpha
	test    rax, rax
	jnz     yep

	call    ft_isdigit
	test    rax, rax
	jnz     yep

	ret

yep:
	mov     rax, 1
	ret
