section .text

;int   isupper(int rdi);
global ft_isupper

ft_isupper:
	cmp     edi, 65
	jl      nope
	cmp     edi, 90
	jg      nope

yep:
	mov     rax, 1
	ret

nope:
	xor     rax, rax
	ret
