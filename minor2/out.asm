; GLOBL
global	$y:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$y:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L0:
; CHAR
	db	0x41
; CHAR
	db	0x42
; CHAR
	db	0x00
; DATA
segment	.data
; ID
	dd	$_L0
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
; ADDRV
	push	dword [$y]
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
$_L1:
; CHAR
	db	0x41
; CHAR
	db	0x42
; TEXT
segment	.text
; ADDR
	push	dword $_L1
; CALL
	call	$_prints
; CALL
	call	$_println
; TRASH
	add	esp, 4
; IMM
	push	dword 97
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
