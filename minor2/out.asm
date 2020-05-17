; GLOBL
global	$cona:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$cona:
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
; ADDRV
	push	dword [$cona]
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L1
; ADDRV
	push	dword [$cona]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_L2
; LABEL
$_L1:
; ADDRV
	push	dword [$cona]
; IMM
	push	dword 2
; ADD
	pop	eax
	add	dword [esp], eax
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
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
