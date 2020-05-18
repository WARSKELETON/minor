; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_L1
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; LABEL
$_L1:
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L2
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; CHAR
	db	0x79
; CHAR
	db	0x65
; CHAR
	db	0x73
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
; JMP
	jmp	dword $_L4
; LABEL
$_L2:
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L5:
; CHAR
	db	0x6E
; CHAR
	db	0x6F
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L5
; CALL
	call	$_prints
; CALL
	call	$_println
; TRASH
	add	esp, 4
; LABEL
$_L4:
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
