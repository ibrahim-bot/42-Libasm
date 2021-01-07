BITS 64

section .text
    global  _ft_strlen

_ft_strlen:
        xor     rcx, 0 ; METTRE 0 DANS RCX

strlen_loop:
        cmp     byte[rdi + rcx], 0 
        jz	fin
        inc     rcx 
        jmp     strlen_loop

fin:
        mov     rax, rcx
        ret