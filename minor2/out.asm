; GLOBL
global	$x:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$x:
; INTEGER
	dd	0
; GLOBL
global	$y:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$y:
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
; IMM
	push	dword 0
; ADDRV
	push	dword [$x]
; LABEL
$_L1:
; ADDRV
	push	dword [$x]
; IMM
	push	dword 2
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L2
; IMM
	push	dword 0
; ADDRV
	push	dword [$y]
; LABEL
$_L3:
; ADDRV
	push	dword [$y]
; IMM
	push	dword 2
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L4
; ADDRV
	push	dword [$x]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; ADDRV
	push	dword [$y]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; ADDRV
	push	dword [$y]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$y]
; JMP
	jmp	dword $_L3
; LABEL
$_L4:
; ADDRV
	push	dword [$x]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; ADDRV
	push	dword [$x]
; JMP
	jmp	dword $_L1
; LABEL
$_L2:
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
