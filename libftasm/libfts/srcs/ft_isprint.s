section .text

;int   isprint(int rdi);
global ft_isprint

ft_isprint:
	cmp     edi, 32
	jl      nope
	cmp     edi, 126
	jg      nope

yep:
	mov     rax, 1
	ret

nope:
	xor     rax, rax
	ret
