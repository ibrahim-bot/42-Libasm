section .text
    global _ft_strcpy

_ft_strcpy:
    push    rbp
    push    rdx
    mov     rbp, rsp
    mov     rdx, 0

strcpy_loop:
    mov     al, byte [rsi + rdx]
    mov     byte [rdi + rdx], al
    inc     rdx
    cmp     al, 0
    jne     strcpy_loop

    mov     rax, rdi
    mov     rsp, rbp
    pop     rdx
    pop     rbp
    ret