global _ft_isprint

section .text:
    call _ft_isprint
    ret

_ft_isprint:
    cmp rdi, 20
    jl nope
    cmp rdi, 126
    jg nope
    mov rax, 1
    ret

nope:
    mov rax, 0
    ret
