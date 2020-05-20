; GLOBL
global	$y:object
; RODATA
segment	.rodata
; ALIGN
align	4
; LABEL
$y:
; INTEGER
	dd	1
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
	sub	esp, 4
; LOCV
	push	dword [ebp+-4]
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
