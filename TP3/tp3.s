	.file	"tp3.c"
	.text
	.globl	_swap
	.def	_swap;	.scl	2;	.type	32;	.endef
_swap:
LFB12:
	.cfi_startproc
	pushl	%ebx
	.cfi_def_cfa_offset 8
	.cfi_offset 3, -8
	movl	8(%esp), %edx
	movl	12(%esp), %eax
	movl	(%edx), %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	%ecx, (%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE12:
	.globl	_decode1
	.def	_decode1;	.scl	2;	.type	32;	.endef
_decode1:
LFB13:
	.cfi_startproc
	pushl	%edi
	.cfi_def_cfa_offset 8
	.cfi_offset 7, -8
	pushl	%esi
	.cfi_def_cfa_offset 12
	.cfi_offset 6, -12
	pushl	%ebx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	16(%esp), %eax
	movl	20(%esp), %ecx
	movl	24(%esp), %edx
	movl	(%ecx), %esi
	movl	(%edx), %ebx
	movl	(%eax), %edi
	movl	%edi, (%ecx)
	movl	%esi, (%edx)
	movl	%ebx, (%eax)
	popl	%ebx
	.cfi_restore 3
	.cfi_def_cfa_offset 12
	popl	%esi
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	popl	%edi
	.cfi_restore 7
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE13:
	.globl	_decode2
	.def	_decode2;	.scl	2;	.type	32;	.endef
_decode2:
LFB14:
	.cfi_startproc
	movl	12(%esp), %eax
	subl	8(%esp), %eax
	imull	4(%esp), %eax
	ret
	.cfi_endproc
LFE14:
	.globl	_cread_alt
	.def	_cread_alt;	.scl	2;	.type	32;	.endef
_cread_alt:
LFB15:
	.cfi_startproc
	movl	4(%esp), %eax
	testl	%eax, %eax
	je	L8
	movl	(%eax), %eax
	ret
L8:
	movl	$0, %eax
	ret
	.cfi_endproc
LFE15:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "\12-- Menu --\0"
LC1:
	.ascii "1. Tester la fonction swap\0"
LC2:
	.ascii "2. Tester la fonction decode1\0"
LC3:
	.ascii "3. Tester la fonction decode2\0"
	.align 4
LC4:
	.ascii "4. Tester la fonction cread_alt\0"
LC5:
	.ascii "0. Quitter\0"
LC6:
	.ascii "Choix : \0"
LC7:
	.ascii "%d\0"
LC8:
	.ascii "Avant swap : a = %d, b = %d\12\0"
LC9:
	.ascii "Apres swap : a = %d, b = %d\12\0"
	.align 4
LC10:
	.ascii "Avant decode1 : x = %ld, y = %ld, z = %ld\12\0"
	.align 4
LC11:
	.ascii "Apres decode1 : x = %ld, y = %ld, z = %ld\12\0"
LC12:
	.ascii "Resultat de decode2 : %ld\12\0"
	.align 4
LC13:
	.ascii "Valeur obtenue avec cread_alt : %ld\12\0"
LC14:
	.ascii "Au revoir !\0"
	.align 4
LC15:
	.ascii "Choix invalide. Veuillez reessayer.\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	.cfi_offset 3, -12
	call	___main
	leal	28(%esp), %ebx
	jmp	L18
L13:
	movl	$20, 8(%esp)
	movl	$10, 4(%esp)
	movl	$LC8, (%esp)
	call	_printf
	movl	$10, 8(%esp)
	movl	$20, 4(%esp)
	movl	$LC9, (%esp)
	call	_printf
L17:
	cmpl	$0, 28(%esp)
	je	L21
L18:
	movl	$LC0, (%esp)
	call	_puts
	movl	$LC1, (%esp)
	call	_puts
	movl	$LC2, (%esp)
	call	_puts
	movl	$LC3, (%esp)
	call	_puts
	movl	$LC4, (%esp)
	call	_puts
	movl	$LC5, (%esp)
	call	_puts
	movl	$LC6, (%esp)
	call	_printf
	movl	%ebx, 4(%esp)
	movl	$LC7, (%esp)
	call	_scanf
	cmpl	$4, 28(%esp)
	ja	L10
	movl	28(%esp), %eax
	jmp	*L12(,%eax,4)
	.section .rdata,"dr"
	.align 4
L12:
	.long	L11
	.long	L13
	.long	L14
	.long	L15
	.long	L16
	.text
L14:
	movl	$3, 12(%esp)
	movl	$2, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC10, (%esp)
	call	_printf
	movl	$2, 12(%esp)
	movl	$1, 8(%esp)
	movl	$3, 4(%esp)
	movl	$LC11, (%esp)
	call	_printf
	jmp	L17
L15:
	movl	$100, 4(%esp)
	movl	$LC12, (%esp)
	call	_printf
	jmp	L17
L16:
	movl	$42, 4(%esp)
	movl	$LC13, (%esp)
	call	_printf
	jmp	L17
L11:
	movl	$LC14, (%esp)
	call	_puts
	jmp	L17
L10:
	movl	$LC15, (%esp)
	call	_puts
	jmp	L17
L21:
	movl	$0, %eax
	movl	-4(%ebp), %ebx
	leave
	.cfi_restore 5
	.cfi_restore 3
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_puts;	.scl	2;	.type	32;	.endef
	.def	_scanf;	.scl	2;	.type	32;	.endef
