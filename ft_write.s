BITS 64

section .text
	global _ft_write

_ft_write:
	mov	rax, 0x2000004
	syscall
	jb	end_err
	jmp	end	

end_err:
	mov	rax, -1
	ret

end:
	ret