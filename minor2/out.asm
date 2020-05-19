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
; LOCA
	pop	eax
	mov	[ebp+0], eax
; TRASH
	add	esp, 4
; LABEL
$_L1:
; LOCV
	push	dword [ebp+0]
; IMM
	push	dword 10
; EQ
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	sete	cl
	mov	[esp], ecx
; JNZ
	pop	eax
	cmp	eax, byte 0
	jne	near $_L3
; LOCV
	push	dword [ebp+0]
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
; JMP
	jmp	dword $_L2
; JMP
	jmp	dword $_L5
; LABEL
$_L4:
; LOCV
	push	dword [ebp+0]
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
	je	near $_L6
; JMP
	jmp	dword $_L2
; JMP
	jmp	dword $_L5
; LABEL
$_L6:
; LABEL
$_L5:
; LOCV
	push	dword [ebp+0]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; LABEL
$_L2:
; LOCV
	push	dword [ebp+0]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+0], eax
; TRASH
	add	esp, 4
; JMP
	jmp	dword $_L1
; LABEL
$_L3:
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
