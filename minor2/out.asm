; GLOBL
global	$i:object
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$i:
; GLOBL
global	$n:object
; BSS
segment	.bss
; ALIGN
align	4
; LABEL
$n:
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
; ADDRV
	push	dword [$i]
; CALL
	call	$_printi
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
extern	$_readi
