; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_fib:function
; LABEL
$_fib:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 2
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L1
; LOCV
	push	dword [ebp+8]
; POP
	pop	eax
; LEAVE
	leave
; RET
	ret
; JMP
	jmp	dword $_L2
; LABEL
$_L1:
; LABEL
$_L2:
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_fib
; TRASH
	add	esp, 4
; PUSH
	push	eax
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 2
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_fib
; TRASH
	add	esp, 4
; PUSH
	push	eax
; ADD
	pop	eax
	add	dword [esp], eax
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L3:
; CHAR
	db	0x51
; CHAR
	db	0x75
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x74
; CHAR
	db	0x65
; CHAR
	db	0x72
; CHAR
	db	0x6D
; CHAR
	db	0x6F
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x73
; CHAR
	db	0xC3
; CHAR
	db	0xA9
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0x65
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x65
; CHAR
	db	0x20
; CHAR
	db	0x46
; CHAR
	db	0x69
; CHAR
	db	0x62
; CHAR
	db	0x6F
; CHAR
	db	0x6E
; CHAR
	db	0x61
; CHAR
	db	0x63
; CHAR
	db	0x63
; CHAR
	db	0x69
; CHAR
	db	0x20
; CHAR
	db	0x61
; CHAR
	db	0x20
; CHAR
	db	0x63
; CHAR
	db	0x61
; CHAR
	db	0x6C
; CHAR
	db	0x63
; CHAR
	db	0x75
; CHAR
	db	0x6C
; CHAR
	db	0x61
; CHAR
	db	0x72
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
; CALL
	call	$_readi
; PUSH
	push	eax
; CALL
	call	$_fib
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
