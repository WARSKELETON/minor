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
	db	0x41
; CHAR
	db	0x50
; CHAR
	db	0x43
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
	call	$_prints
; CALL
	call	$_println
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x41
; CHAR
	db	0x41
; CHAR
	db	0x41
; CHAR
	db	0x50
; CHAR
	db	0x43
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L2
; CALL
	call	$_prints
; CALL
	call	$_println
; TRASH
	add	esp, 4
; IMM
	push	dword 2
; IMM
	push	dword 65
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
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
; TEXT
segment	.text
; ADDR
	push	dword $_L3
; CALL
	call	$_prints
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