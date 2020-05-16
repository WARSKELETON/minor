; GLOBL
global	$cona:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$cona:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x63
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x61
; CHAR
	db	0x00
; DATA
segment	.data
; ID
	dd	$_L1
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; ADDRV
	push	dword [$cona]
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
; RET
	ret
; DATA
segment	.data
; EXTRN
extern	$_prints
; EXTRN
extern	$_printi
; EXTRN
extern	$_println
; EXTRN
extern	$_readi
