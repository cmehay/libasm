section .text

;char  *ft_strcat(char *rdi, const char *rsi);
global ft_strcat

ft_strcat:
	mov     rax, rdi

loop_dest:
	inc     rdi
	cmp     BYTE [rdi], 0x0
	jne     loop_dest

loop_append:
	mov     cl, BYTE [rsi]
	mov     BYTE [rdi], cl
	inc     rdi
	inc     rsi
	cmp     BYTE [rsi], 0x0
	jne     loop_append

	mov     BYTE [rdi], 0x0

	ret
