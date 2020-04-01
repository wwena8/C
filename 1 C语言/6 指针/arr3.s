	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	movl	$0, -4(%rbp)
	movq	l___const.main.a(%rip), %rax
	movq	%rax, -32(%rbp)
	movq	l___const.main.a+8(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	l___const.main.a+16(%rip), %rax
	movq	%rax, -16(%rbp)
	movl	$0, -36(%rbp)
LBB0_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB0_3 Depth 2
	cmpl	$2, -36(%rbp)
	jge	LBB0_8
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	$0, -40(%rbp)
LBB0_3:                                 ##   Parent Loop BB0_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	cmpl	$3, -40(%rbp)
	jge	LBB0_6
## %bb.4:                               ##   in Loop: Header=BB0_3 Depth=2
	movslq	-36(%rbp), %rax
	imulq	$12, %rax, %rax
	leaq	-32(%rbp), %rcx
	addq	%rax, %rcx
	movslq	-40(%rbp), %rax
	movl	(%rcx,%rax,4), %esi
	leaq	L_.str(%rip), %rdi
	movb	$0, %al
	callq	_printf
	movl	%eax, -44(%rbp)         ## 4-byte Spill
## %bb.5:                               ##   in Loop: Header=BB0_3 Depth=2
	movl	-40(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -40(%rbp)
	jmp	LBB0_3
LBB0_6:                                 ##   in Loop: Header=BB0_1 Depth=1
	movl	$10, %edi
	callq	_putchar
	movl	%eax, -48(%rbp)         ## 4-byte Spill
## %bb.7:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB0_1
LBB0_8:
	xorl	%edi, %edi
	callq	_exit
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__const
	.p2align	4               ## @__const.main.a
l___const.main.a:
	.long	5                       ## 0x5
	.long	1                       ## 0x1
	.long	7                       ## 0x7
	.long	2                       ## 0x2
	.long	8                       ## 0x8
	.long	3                       ## 0x3

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d "


.subsections_via_symbols
