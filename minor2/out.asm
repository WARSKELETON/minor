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
	db	0x61
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
; IMM
	push	dword 1
; IMM
	push	dword 3
; ADD
	pop	eax
	add	dword [esp], eax
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
	db	0x62
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
; IMM
	push	dword 3
; IMM
	push	dword 4
; SUB
	pop	eax
	sub	dword [esp], eax
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
	db	0x63
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
; IMM
	push	dword 2
; IMM
	push	dword 5
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
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
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L7:
; CHAR
	db	0x64
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L7
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 6
; IMM
	push	dword 3
; DIV
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
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
$_L8:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L8
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L9:
; CHAR
	db	0x65
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L9
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 11
; IMM
	push	dword 5
; MOD
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L10:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L10
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L11:
; CHAR
	db	0x66
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L11
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 4
; IMM
	push	dword 3
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L12:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L12
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L13:
; CHAR
	db	0x67
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L13
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 4
; IMM
	push	dword 1
; NE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setne	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L14:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L14
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L15:
; CHAR
	db	0x68
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L15
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 1
; IMM
	push	dword 2
; GE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L16:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L16
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L17:
; CHAR
	db	0x69
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L17
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 1
; IMM
	push	dword 2
; LT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setl	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L18:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L18
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L19:
; CHAR
	db	0x6A
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L19
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 1
; IMM
	push	dword 2
; LE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setle	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L20:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L20
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L21:
; CHAR
	db	0x6B
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L21
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 1
; IMM
	push	dword 2
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L22:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L22
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L23:
; CHAR
	db	0x6C
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L23
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 2
; COPY
	push	dword [esp]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L24
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; LABEL
$_L24:
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L25:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L25
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L26:
; CHAR
	db	0x6D
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L26
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 2
; COPY
	push	dword [esp]
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_L27
; TRASH
	add	esp, 4
; IMM
	push	dword 1
; LABEL
$_L27:
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L28:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L28
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L29:
; CHAR
	db	0x6E
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L29
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 3
; IMM
	push	dword 2
; CALL
	call	$_pfpow
; TRASH
	add	esp, 8
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
$_L30:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L30
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L31:
; CHAR
	db	0x6F
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L31
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; IMM
	push	dword 3
; CALL
	call	$_pfpow
; TRASH
	add	esp, 8
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
$_L32:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L32
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L33:
; CHAR
	db	0x70
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L33
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 3
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L34:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L34
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L35:
; CHAR
	db	0x71
; CHAR
	db	0x3A
; CHAR
	db	0x20
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L35
; CALL
	call	$_prints
; TRASH
	add	esp, 4
; IMM
	push	dword 0
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L36:
; CHAR
	db	0x0A
; CHAR
	db	0x00
; TEXT
segment	.text
; ADDR
	push	dword $_L36
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
extern	$_pfpow
; EXTRN
extern	$_pfstrcmp
