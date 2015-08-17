section .text

;char  *ft_strdup(const char *rdi);
global ft_strdup
extern ft_strlen
extern ft_memcpy
extern malloc

ft_strdup:
	enter   16, 0

	push 	rdi
	call    ft_strlen
	inc     rax
	push 	rax

	mov     rdi, rax             ;size
	call    malloc

	test    rax, rax
	jz      ft_strdup_error

	mov     rdi, rax             ;dest
	pop     rdx                  ;n
	pop     rsi,                 ;src
	call    ft_memcpy

ft_strdup_error:
	leave
	ret
