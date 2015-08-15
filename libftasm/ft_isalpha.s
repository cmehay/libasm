global _ft_isalpha

section .text:
    call _ft_isalpha
    ret

_ft_isalpha:
    cmp rdi, 'a'
    jge is_min
    cmp rdi, 'A'
    jge is_maj
    jmp nope

is_maj:
    cmp rdi, 'Z'
    jle yep
    jmp nope

is_min:
    cmp rdi, 'z'
    jle yep
    jmp nope

yep:
    mov rax, 1
    ret

nope:
    mov rax, 0
    ret
