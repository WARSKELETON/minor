	.file	"min.c"
	.text
	.globl	pfpow
	.type	pfpow, @function
pfpow:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$16, %esp
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	movl	$1, -4(%ebp)
	jmp	.L2
.L3:
	movl	-4(%ebp), %eax
	imull	8(%ebp), %eax
	movl	%eax, -4(%ebp)
	subl	$1, 12(%ebp)
.L2:
	cmpl	$0, 12(%ebp)
	jg	.L3
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	pfpow, .-pfpow
	.globl	pfstrcmp
	.type	pfstrcmp, @function
pfstrcmp:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	call	__x86.get_pc_thunk.ax
	addl	$_GLOBAL_OFFSET_TABLE_, %eax
	jmp	.L6
.L8:
	addl	$1, 8(%ebp)
	addl	$1, 12(%ebp)
.L6:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	je	.L7
	movl	8(%ebp), %eax
	movzbl	(%eax), %edx
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	cmpb	%al, %dl
	je	.L8
.L7:
	movl	8(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %edx
	movl	12(%ebp), %eax
	movzbl	(%eax), %eax
	movzbl	%al, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	pfstrcmp, .-pfstrcmp
	.section	.text.__x86.get_pc_thunk.ax,"axG",@progbits,__x86.get_pc_thunk.ax,comdat
	.globl	__x86.get_pc_thunk.ax
	.hidden	__x86.get_pc_thunk.ax
	.type	__x86.get_pc_thunk.ax, @function
__x86.get_pc_thunk.ax:
.LFB2:
	.cfi_startproc
	movl	(%esp), %eax
	ret
	.cfi_endproc
.LFE2:
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
