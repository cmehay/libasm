section .text

;int   abs(int rdi);
global ft_abs

ft_abs:
	movsx   rax, edi

	cmp     rax, 0
	jge     end

	not     rax
	inc     rax

end:
	ret
