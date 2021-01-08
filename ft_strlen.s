BITS 64

section .text
    global  _ft_strlen

_ft_strlen:
        mov     rcx, 0 ; METTRE 0 DANS RCX

strlen_loop:
        cmp     byte[rdi + rcx], 0 ; compare le caracter avec \0
        jz	fin                ; si == zero
        inc     rcx                ; increment rcx
        jmp     strlen_loop        ; boucle on recommence

fin:
        mov     rax, rcx           ; rax == valeur de retour ; on met le nb cb dans rax     
        ret                        ; on return     