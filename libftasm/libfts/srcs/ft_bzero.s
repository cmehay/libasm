section .text

;void  ft_bzero(void *rdi, size_t rsi);
global ft_bzero

ft_bzero:
	test    rsi, rsi
	jz      end

	xor     rcx, rcx

loop:
	mov     BYTE [rdi + rcx], 0x0
	inc     rcx
	cmp     rcx, rsi
	jne     loop

end:
	ret
