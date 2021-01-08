BITS 64

section .text
    global _ft_read

_ft_read:
    mov	rax, 0x2000003
	syscall
	jb	end_err
	jmp	end	

end_err:
	mov	rax, -1
	ret

end:
	ret