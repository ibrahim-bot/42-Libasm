BITS 64

section .text
    global _ft_strcpy

_ft_strcpy:
    push    rbp
    mov     rbp, rsp
    mov     rcx, 0

strcpy_loop:
    mov     al, byte[rsi + rcx]
    mov     byte[rdi + rcx], al
    inc     rcx
    cmp     al, 0
    jne     strcpy_loop ; jne = tand pas egal 0
    jz      strcpy_end  ; jz = si zero

strcpy_end:
    mov     rax, rdi
    mov     rsp, rbp
    pop     rbp
    ret