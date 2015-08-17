section .text

;int   isdigit(int rdi);
global ft_isdigit

ft_isdigit:
	cmp     edi, '0'
	jl      nope
	cmp     edi, '9'
	jg      nope

yep:
	mov     rax, 1
	ret

nope:
	xor     rax, rax
	ret
