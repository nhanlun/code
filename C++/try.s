	.file	"try.cpp"
	.text
	.p2align 4,,15
	.globl	_Z11doSomethingv
	.type	_Z11doSomethingv, @function
_Z11doSomethingv:
.LFB0:
	.cfi_startproc
	xorl	%edx, %edx
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L3:
	leaq	(%rax,%rdx), %rcx
	testb	$1, %dl
	cmove	%rcx, %rax
	addq	$1, %rdx
	cmpq	$10, %rdx
	jne	.L3
	rep ret
	.cfi_endproc
.LFE0:
	.size	_Z11doSomethingv, .-_Z11doSomethingv
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
