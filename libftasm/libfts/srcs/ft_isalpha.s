section .text

;int   isalpha(int rdi);
global ft_isalpha

ft_isalpha:
	cmp     edi, 'A'
	jl      nope
	cmp     edi, 'z'
	jg      nope
	cmp     edi, 'Z'
	jle     yep
	cmp     edi, 'a'
	jge     yep

nope:
	xor     rax, rax
	ret

yep:
	mov     rax, 1
	ret
