global _ft_isalnum

section .text
    call _ft_isalnum
    extern _ft_isalpha
    extern _ft_isdigit
    ret

_ft_isalnum:
    call _ft_isalpha
    cmp rax, 1
    je yep
    call _ft_isdigit
    cmp rax, 1
    je yep
    mov rax, 0
    ret

yep:
    mov rax, 1
    ret
