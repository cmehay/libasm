global _ft_isascii

section .text:
    call _ft_isascii
    ret

_ft_isascii:
    cmp rdi, 0
    jl nope
    cmp rdi, 127
    jg nope
    mov rax, 1
    ret

nope:
    mov rax, 0
    ret
