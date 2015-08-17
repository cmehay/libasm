section .data
c_newline:
	.string db "", 10                ; '\n'
	.len equ $ - c_newline.string

section .text

;int   ft_puts(const char *rdi);
global ft_puts
extern ft_strlen

ft_puts:
	push    rdi                      ;message to write
	call    ft_strlen
	pop     rdi

	mov     rdx, rax                 ;message length
	mov     rsi, rdi                 ;message to write
	mov     rdi, 1                   ;file descriptor (stdout)
	mov     rax, SYSCALL_UNIX(WRITE) ;system call number (sys_write)
	syscall                          ;call kernel

	cmp     rax, 0
	jl      ft_puts_error

	mov     rdx, c_newline.len
	lea     rsi, [rel c_newline.string]
	mov     rdi, 1
	mov     rax, SYSCALL_UNIX(WRITE)
	syscall
	ret

	cmp     rax, 0
	jl      ft_puts_error

	ret

ft_puts_error:
	mov     rax, -1
	ret
