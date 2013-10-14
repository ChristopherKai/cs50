	.file	"hello.c"
	.text
	.globl	main
	.align	16, 0x90
	.type	main,@function
main:                                   # @main
# BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$120, %esp
	movl	$72, %eax
	movl	$0, -4(%ebp)
	movl	$72, (%esp)
	movl	%eax, -8(%ebp)          # 4-byte Spill
	calll	putchar
	movl	$101, %ecx
	movl	$101, (%esp)
	movl	%eax, -12(%ebp)         # 4-byte Spill
	movl	%ecx, -16(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$108, %ecx
	movl	$108, (%esp)
	movl	%eax, -20(%ebp)         # 4-byte Spill
	movl	%ecx, -24(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$108, %ecx
	movl	$108, (%esp)
	movl	%eax, -28(%ebp)         # 4-byte Spill
	movl	%ecx, -32(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$111, %ecx
	movl	$111, (%esp)
	movl	%eax, -36(%ebp)         # 4-byte Spill
	movl	%ecx, -40(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$44, %ecx
	movl	$44, (%esp)
	movl	%ecx, -44(%ebp)         # 4-byte Spill
	movl	%eax, -48(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$32, %ecx
	movl	$32, (%esp)
	movl	%ecx, -52(%ebp)         # 4-byte Spill
	movl	%eax, -56(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$119, %ecx
	movl	$119, (%esp)
	movl	%eax, -60(%ebp)         # 4-byte Spill
	movl	%ecx, -64(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$111, %ecx
	movl	$111, (%esp)
	movl	%eax, -68(%ebp)         # 4-byte Spill
	movl	%ecx, -72(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$114, %ecx
	movl	$114, (%esp)
	movl	%eax, -76(%ebp)         # 4-byte Spill
	movl	%ecx, -80(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$108, %ecx
	movl	$108, (%esp)
	movl	%eax, -84(%ebp)         # 4-byte Spill
	movl	%ecx, -88(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$100, %ecx
	movl	$100, (%esp)
	movl	%eax, -92(%ebp)         # 4-byte Spill
	movl	%ecx, -96(%ebp)         # 4-byte Spill
	calll	putchar
	movl	$33, %ecx
	movl	$33, (%esp)
	movl	%ecx, -100(%ebp)        # 4-byte Spill
	movl	%eax, -104(%ebp)        # 4-byte Spill
	calll	putchar
	movl	-4(%ebp), %ecx
	movl	%eax, -108(%ebp)        # 4-byte Spill
	movl	%ecx, %eax
	addl	$120, %esp
	popl	%ebp
	ret
.Ltmp0:
	.size	main, .Ltmp0-main


	.section	".note.GNU-stack","",@progbits
