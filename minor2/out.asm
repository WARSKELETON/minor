; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_fatorial:function
; LABEL
$_fatorial:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LOCV
	push	dword [ebp+8]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L1
; LOCV
	push	dword [ebp+8]
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_fatorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; JMP
	jmp	dword $_L2
; LABEL
$_L1:
; IMM
	push	dword 1
; LABEL
$_L2:
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
	sub	esp, 0
; IMM
	push	dword 4
; CALL
	call	$_fatorial
; TRASH
	add	esp, 4
; PUSH
	push	eax
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
