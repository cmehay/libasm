section .text

;int   isspace(int rdi);
global ft_isspace

ft_isspace:
	cmp     edi, 0x20
	je      yep
	cmp     edi, 0x0D
	jg      nope
	cmp     edi, 0x09
	jle     nope
	jmp     yep

nope:
	xor     rax, rax
	ret

yep:
	mov     rax, 1
	ret
