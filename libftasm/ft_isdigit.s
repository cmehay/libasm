global _ft_isdigit

section .text:
    call _ft_isdigit
    ret

_ft_isdigit:
    cmp rdi, '0'
    jl nope
    cmp rdi, '9'
    jg nope
    mov rax, 1
    ret

nope:
    mov rax, 0
    ret
