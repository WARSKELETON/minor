; GLOBL
global	$x:object
; DATA
segment	.data
; ALIGN
align	4
; LABEL
$x:
; INTEGER
	dd	2
; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_main:function
; LABEL
$_main:
; IMM
	push	dword 1
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+0], eax
; TRASH
	add	esp, 4
; IMM
	push	dword 3
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+4], eax
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+0]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; LOCV
	push	dword [ebp+4]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; ADDRV
	push	dword [$x]
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
