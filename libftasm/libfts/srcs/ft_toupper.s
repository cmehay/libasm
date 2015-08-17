section .text

;int   toupper(int rdi);
global ft_toupper

ft_toupper:
	cmp     edi, 'a'
	jl      do_nothing
	cmp     edi, 'z'
	jg      do_nothing

	sub     edi, 32
	movsx   rax, edi
	ret

do_nothing:
	movsx   rax, edi
	ret
