BITS 64

section .text
    global _ft_strcmp

_ft_strcmp:
        push    rbp
        mov     rbp, rsp
        mov     rcx, 0

strcmp_loop:
        mov     al, byte[rsi + rcx]     ; POUR COMPARER
        cmp     byte[rdi + rcx], al
        ja      end2                    ; return 1 SI OP1 > OP2
        jb      end3                    ; return -1 SI OP1 < OP2
        je      end                    ; return 0 SI OP1 == OP2 

end:
        inc     rcx
        cmp     al, 0
        ja      strcmp_loop
        mov     rax, 0                  ; rax valeur de retour
        mov     rsp, rbp
        pop     rbp
        ret

end2:
        mov     rax, 1
        mov     rsp, rbp
        pop     rbp
        ret

end3:
        mov     rax, -1
        mov     rsp, rbp
        pop     rbp
        ret