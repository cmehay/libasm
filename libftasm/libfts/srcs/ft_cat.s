%define BUF_SIZE 4096

section .text

;void  ft_cat(const int rdi);
global ft_cat

ft_cat:
    enter   BUF_SIZE, 0

    mov     rsi, rsp

    movsx   r8, edi

loop:
    mov     rdi, r8
    mov     rdx, BUF_SIZE
    mov     rax, SYSCALL_UNIX(READ)
    syscall
    cmp     rax, 0
    jle     end

    mov     rdi, 1
    mov     rdx, rax
    mov     rax, SYSCALL_UNIX(WRITE)
    syscall
    cmp     rax, 0
    jl      end

    jmp     loop

end:
    leave
    ret
