	.file	"vectors.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC1:
	.string	"%*\n"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB2:
	.section	.text.startup,"ax",@progbits
.LHOTB2:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB47:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movdqa	.LC0(%rip), %xmm0
	leaq	16(%rsp), %rbp
	movq	%rsp, %rbx
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	movaps	%xmm0, (%rsp)
	.p2align 4,,10
	.p2align 3
.L2:
	movswl	(%rbx), %edx
	xorl	%eax, %eax
	movl	$.LC1, %esi
	movl	$1, %edi
	addq	$2, %rbx
	call	__printf_chk
	cmpq	%rbp, %rbx
	jne	.L2
	xorl	%eax, %eax
	movq	24(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L7
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L7:
	.cfi_restore_state
	call	__stack_chk_fail
	.cfi_endproc
.LFE47:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE2:
	.section	.text.startup
.LHOTE2:
	.section	.rodata.cst16,"aM",@progbits,16
	.align 16
.LC0:
	.value	2
	.value	2
	.value	2
	.value	2
	.value	2
	.value	2
	.value	2
	.value	2
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
