section .text

;void  *ft_memset(void *rdi, int rsi, size_t rdx);
global ft_memset

ft_memset:
	mov     rax, rdi

	mov     rcx, rdx
	mov     al, sil
	cld
	rep stosb

	ret
