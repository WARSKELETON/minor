; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$i:
; BYTE
	resb	4
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$n:
; BYTE
	resb	4
; GLOBL
global	$d:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$d:
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
; CALL
	call	$_readi
; PUSH
	push	eax
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$n], eax
; TRASH
	add	esp, 4
; ADDRV
	push	dword [$n]
; IMM
	push	dword 2
; GT
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setg	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L1
; IMM
	push	dword 2
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$i], eax
; TRASH
	add	esp, 4
; LABEL
$_L2:
; ADDRV
	push	dword [$i]
; ADDRV
	push	dword [$n]
; IMM
	push	dword 2
; DIV
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	eax
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_L4
; ADDRV
	push	dword [$n]
; ADDRV
	push	dword [$i]
; MOD
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L5
; ADDRV
	push	dword [$n]
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
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x27
; CHAR
	db	0x20
; CHAR
	db	0x64
; CHAR
	db	0x69
; CHAR
	db	0x76
; CHAR
	db	0x69
; CHAR
	db	0x73
; CHAR
	db	0x69
; CHAR
	db	0x76
; CHAR
	db	0x65
; CHAR
	db	0x6C
; CHAR
	db	0x20
; CHAR
	db	0x70
; CHAR
	db	0x6F
; CHAR
	db	0x72
; CHAR
	db	0x20
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
; ADDRV
	push	dword [$i]
; CALL
	call	$_printi
; TRASH
	add	esp, 4
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$_L7:
; CHAR
	db	0x0A
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
; ADDRV
	push	dword [$d]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$d], eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_L8
; LABEL
$_L5:
; LABEL
$_L8:
; LABEL
$_L3:
; ADDRV
	push	dword [$i]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; ADDRA
	pop	eax
	mov	[$i], eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_L2
; LABEL
$_L4:
; ADDRV
	push	dword [$d]
; IMM
	push	dword 0
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L9
; ADDRV
	push	dword [$n]
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
	db	0x20
; CHAR
	db	0x65
; CHAR
	db	0x27
; CHAR
	db	0x20
; CHAR
	db	0x70
; CHAR
	db	0x72
; CHAR
	db	0x69
; CHAR
	db	0x6D
; CHAR
	db	0x6F
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
; JMP
	jmp	dword $_L11
; LABEL
$_L9:
; LABEL
$_L11:
; JMP
	jmp	dword $_L12
; LABEL
$_L1:
; LABEL
$_L12:
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
extern	$_readi
