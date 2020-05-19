; TEXT
segment	.text
; ALIGN
align	4
; GLOBL
global	$_double:function
; LABEL
$_double:
; ENTER
	push	ebp
	mov	ebp, esp
	sub	esp, 4
; LOCV
	push	dword [ebp+-4]
; LOCV
	push	dword [ebp+8]
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
; IMM
	push	dword 2
; MUL
	pop	eax
	imul	dword eax, [esp]
	mov	[esp], eax
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
; IMM
	push	dword 0
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
; TRASH
	add	esp, 4
; LABEL
$_L1:
; LOCV
	push	dword [ebp+-4]
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
	push	dword [ebp+-4]
; IMM
	push	dword 2
; MOD
	pop	ecx
	pop	eax
	cdq
	idiv	ecx
	push	edx
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
	push	dword [ebp+-4]
; IMM
	push	dword 5
; GE
	pop	eax
	xor	ecx, ecx
	cmp	[esp], eax
	setge	cl
	mov	[esp], ecx
; JZ
	pop	eax
	cmp	eax, byte 0
	je	near $_L6
; JMP
	jmp	dword $_L3
; JMP
	jmp	dword $_L5
; LABEL
$_L6:
; LABEL
$_L5:
; LOCV
	push	dword [ebp+-4]
; CALL
	call	$_printi
; CALL
	call	$_println
; TRASH
	add	esp, 4
; LABEL
$_L2:
; LOCV
	push	dword [ebp+-4]
; IMM
	push	dword 1
; ADD
	pop	eax
	add	dword [esp], eax
; COPY
	push	dword [esp]
; LOCA
	pop	eax
	mov	[ebp+-4], eax
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
