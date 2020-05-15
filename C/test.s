	.file	"test.c"
	.text
	.p2align 4,,15
	.globl	doSomething
	.type	doSomething, @function
doSomething:
.LFB0:
	.cfi_startproc
	xorq	%rax, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	doSomething, .-doSomething
	.ident	"GCC: (Ubuntu 7.5.0-3ubuntu1~18.04) 7.5.0"
	.section	.note.GNU-stack,"",@progbits
