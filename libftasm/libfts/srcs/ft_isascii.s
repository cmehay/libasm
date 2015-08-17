section .text

;int   isascii(int rdi);
global ft_isascii

ft_isascii:
	cmp     edi, 0
	jl      nope
	cmp     edi, 127
	jg      nope

	mov     rax, 1
	ret

nope:
	xor     rax, rax
	ret
