	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
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
	subq	$96, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	$97, %eax
	movl	%eax, %edi
	movl	%eax, -20(%rbp)         ## 4-byte Spill
	callq	_putchar
	leaq	L_.str(%rip), %rcx
	movl	$1, %edx
	movl	$1, %esi
	movl	%edx, %edi
	movq	%rsi, -32(%rbp)         ## 8-byte Spill
	movq	%rcx, %rsi
	movq	-32(%rbp), %r8          ## 8-byte Reload
	movl	%edx, -36(%rbp)         ## 4-byte Spill
	movq	%r8, %rdx
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movq	%rcx, -48(%rbp)         ## 8-byte Spill
	callq	_write
	movl	-20(%rbp), %edi         ## 4-byte Reload
	movq	%rax, -56(%rbp)         ## 8-byte Spill
	callq	_putchar
	movl	-36(%rbp), %edi         ## 4-byte Reload
	movq	-48(%rbp), %rsi         ## 8-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movl	%eax, -60(%rbp)         ## 4-byte Spill
	callq	_write
	movl	-20(%rbp), %edi         ## 4-byte Reload
	movq	%rax, -72(%rbp)         ## 8-byte Spill
	callq	_putchar
	movl	-36(%rbp), %edi         ## 4-byte Reload
	movq	-48(%rbp), %rsi         ## 8-byte Reload
	movq	-32(%rbp), %rdx         ## 8-byte Reload
	movl	%eax, -76(%rbp)         ## 4-byte Spill
	callq	_write
	movl	$10, %edi
	movq	%rax, -88(%rbp)         ## 8-byte Spill
	callq	_putchar
	xorl	%edi, %edi
	movl	%eax, -92(%rbp)         ## 4-byte Spill
	callq	_exit
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"b"


.subsections_via_symbols
