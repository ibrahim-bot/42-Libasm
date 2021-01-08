extern _malloc, _ft_strlen, _ft_strcpy

section .text
	global  _ft_strdup 

_ft_strdup:
	push	rbp		; initialiser la pile
	mov	rbp, rsp	; avoir un pointeur sur le debut et la fin de la pile
	push	r15		
	mov	r15, rdi	; r15 = copie du (str)
	cmp	r15, 0		; verifie si str == NULL
	je	exit
	call	_ft_strlen	; rax = strlen(str)
	inc	rax		; ajoute +1 a rax pour '\0'
	mov 	rdi, rax	; donne a rdi la taille a allouer
	push	rax		; alligner la stack avant le malloc
	call	_malloc		; malloc
	cmp	rax, 0		; si error malloc
	je	ret_null
	mov	rdi, rax	; rdi copie le pointeur de la zone allouer
	mov 	rsi, r15	; rsi(src) pour recuperer la str a copier
	pop	rax		; on nettoye la stack de rax 
	call	_ft_strcpy	; rdi la valeur de retour egal a la str malloc
	pop	r15		; on nettoye la stack
	leave
	ret

exit:
	pop 	r15
	leave
	ret

ret_null:
	pop	rax
	pop 	r15
	leave
	ret