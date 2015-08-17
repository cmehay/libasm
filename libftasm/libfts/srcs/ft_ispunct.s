section .text

;int   ispunct(int rdi);
global ft_ispunct
extern ft_isprint
extern ft_isalnum

ft_ispunct:
	cmp     edi, 32
	je      nope

	call    ft_isprint
	test    rax, rax
	jz      nope

	call    ft_isalnum
	test    rax, rax
	jnz     nope

yep:
	mov     rax, 1
	ret

nope:
	mov     rax, 0
	ret
