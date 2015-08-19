section .text

; ft_atoi(const char* fdi)
global ft_atoi
extern ft_isspace
extern ft_isdigit

ft_atoi:
    xor     rcx, rcx
    xor     rax, rax
    xor     r10, r10
    mov     r11, 0x30 ; set '0'
    mov     r12, rdi

shift_space:
    mov     rdi, [r12]
    and     rdi, 0xFF ; mask
    cmp     rdi, 0
    je      return
    call    ft_isspace
    cmp     rax, 0
    je      shift_symbol
    inc     r12
    jmp     shift_space


shift_symbol:
    cmp     rdi, 0x2D ; -
    je      set_min
    cmp     rdi, 0x2B ; +
    je      shift_plus
    jmp     atoi_first

set_min:
    mov     r9, 1
    inc     r12
    jmp     atoi_first

shift_plus:
    inc     r12


atoi_first:
    mov     rdi, [r12]
    and     rdi, 0xFF ; mask
    call    ft_isdigit
    cmp     rax, 0
    je      return
    sub     rdi, r11
    mov     r10, rdi
    inc     r12

atoi_next:
    mov     rdi, [r12]
    and     rdi, 0xFF ; mask
    call    ft_isdigit
    cmp     rax, 0
    je      reverse
    imul    r10, 10
    sub     rdi, r11
    mov     r13, rdi
    add     r10, r13
    inc     r12
    jmp     atoi_next

reverse:
    mov     rax, r10
    cmp     rax, 0
    je      return
    cmp     r9, 1
    jne     return

    not     rax ; inverse number
    inc     rax

return:
    ret
