; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_movedisk:function
; LABEL
$_movedisk:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LOCV
	push	dword [ebp+8]
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
	db	0x20
; CHAR
	db	0x2D
; CHAR
	db	0x3E
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
; LOCV
	push	dword [ebp+12]
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
; LEAVE
	leave
; RET
	ret
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_movetower:function
; LABEL
$_movetower:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 0
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 0
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L3
; LOCV
	push	dword [ebp+16]
; LOCV
	push	dword [ebp+20]
; LOCV
	push	dword [ebp+12]
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_movetower
; TRASH
	add	esp, -8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+16]
; LOCV
	push	dword [ebp+12]
; CALL
	call	$_movedisk
; TRASH
	add	esp, 0
; PUSH
	push	eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+12]
; LOCV
	push	dword [ebp+16]
; LOCV
	push	dword [ebp+20]
; LOCV
	push	dword [ebp+8]
; IMM
	push	dword 1
; SUB
	pop	eax
	sub	dword [esp], eax
; CALL
	call	$_movetower
; TRASH
	add	esp, -8
; PUSH
	push	eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_L4
; LABEL
$_L3:
; LABEL
$_L4:
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
	push	dword 2
; IMM
	push	dword 3
; IMM
	push	dword 1
; IMM
	push	dword 3
; CALL
	call	$_movetower
; TRASH
	add	esp, -8
; PUSH
	push	eax
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
