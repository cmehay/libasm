section .text

;int   islower(int rdi);
global ft_islower

ft_islower:
	cmp     edi, 97
	jl      nope
	cmp     edi, 122
	jg      nope

yep:
	mov     rax, 1
	ret

nope:
	xor     rax, rax
	ret
