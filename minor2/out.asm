; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_double:function
; LABEL
$_double:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; IMM
	push	dword 2
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-4]
; LOCV
	push	dword [ebp+8]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword 2
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 8
; IMM
	push	dword 2
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-8], eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-8]
; CALL
	call	$_double
; TRASH
	add	esp, 4
; PUSH
	push	eax
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-4]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; LEAVE
	leave
; RET
	ret
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_readi
