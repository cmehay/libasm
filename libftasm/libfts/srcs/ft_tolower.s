section .text

;int   tolower(int rdi);
global ft_tolower

ft_tolower:
	cmp     edi, 'A'
	jl      do_nothing
	cmp     edi, 'Z'
	jg      do_nothing

	add     edi, 32
	movsx   rax, edi
	ret

do_nothing:
	movsx   rax, edi
	ret
