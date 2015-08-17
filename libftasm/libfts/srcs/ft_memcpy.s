section .text

;void  *memcpy(void *rdi, const void *rsi, size_t rdx);
global ft_memcpy

ft_memcpy:
	mov     rax, rdi

	mov     rcx, rdx
	cld
	rep movsb

	ret
