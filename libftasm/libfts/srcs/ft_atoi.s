section .text

; ft_atoi(const char* fdi)
global ft_atoi
extern ft_isspace
extern ft_isdigit

ft_atoi:
    mov     rcx, 0
    mov     rdx, rdi
    mov     r10, 0

shift_space:
    mov     rdi, [rdx]
    cmp     rdi, 0
    je      return
    call    ft_isspace
    cmp     rax, 0
    je      shift_symbol
    inc     rdx
    jmp     shift_space


shift_symbol:
    cmp     rdi, 0x2D ; -
    je      set_min
    cmp     rdi, 0x2B ; +
    je      shift_plus
    jmp     atoi

set_min:
    mov     r9, 1
    inc     rdx
    jmp     atoi

shift_plus:
    inc     rdx

atoi:
    mov     r11, 0x30 ; set '0'
    mov     rax, 10 ; set mul
    mul     r10
    mov     r10, rax
    mov     rdi, [rdx]
    call    ft_isdigit
    cmp     rax, 0
    je      reverse
    add     r11, [rdx]
    add     r10, r11
    jmp     atoi

reverse:
    mov     rax, r10
    cmp     r9, 1
    jne     return

    not     rax ; inverse number
    inc     rax

return:
    ret
