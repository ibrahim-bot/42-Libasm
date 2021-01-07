BITS 64

section .text
    global _ft_strcmp

_ft_strcmp:
        xor     rcx, 0

strcmp_loop:
        mov     al ,byte[rdi + rcx]  ; POUR COMPARER
        inc     rcx
        je      strcmp_loop          ; SI OP1 == OP2 EGAL
        ja      ; SI OP1 > OP2  SUPERIEUR 
        jb      ; SI OP1 < OP2  INFERIEUR


fin:
    mov     rax, rcx ; rax valeur de retour
    ret