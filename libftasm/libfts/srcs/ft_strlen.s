section .text

;size_t ft_strlen(const char *rdi);
global  ft_strlen

ft_strlen:
	xor         al, al

	xor         rcx, rcx
	not         rcx
	cld
	repne scasb

	not         rcx
	dec         rcx

	mov         rax, rcx

	ret
