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
	sub	esp, 0
; ADDRV
	push	dword [$y]
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
	sub	esp, 0
; IMM
	push	dword 4
; CALL
	call	$_double
; TRASH
	add	esp, 4
; PUSH
	push	eax
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L1
; CALL
	call	$_prints
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
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_readi
