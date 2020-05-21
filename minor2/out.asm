; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$x:
; BYTE
	resb	4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$y:
; INTEGER
	dd	10
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$z:
; INTEGER
	dd	0
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x78
; CHAR
	db	0x3A
; CHAR
	db	0x20
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
; ADDRV
	push	dword [$x]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L2
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; CHAR
	db	0x79
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L3
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; ADDRV
	push	dword [$y]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L4:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L4
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L5:
; CHAR
	db	0x7A
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L5
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; ADDRV
	push	dword [$z]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L6:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L6
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
