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
	sub	esp, 12
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L1:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L1
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L2:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x00
; CHAR
	db	0x20
; CHAR
	db	0x00
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x00
; CHAR
	db	0x0A
; CHAR
	db	0x00
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L2
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-8], eax
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; CHAR
	db	0x68
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x6C
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x77
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x6C
; CHAR
	db	0x64
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L3
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-12], eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-4]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-8]
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+-12]
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
; EXTRN
extern	$_pow
