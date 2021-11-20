# 313547085 Dor Levy
.text 					# the beginning of the code
.globl even 				# defining the label “even”.
.type even, @function 			# defining “even” as function.        
even:
	pushq	%rbp			# saving the old frame pointer.
	movq 	%rsp,%rbp		# creating the new frame pointer.
	movl 	%esi,%ecx		# set the first parameter to ecx
	movl 	%edi,%eax		# set the second parameter to eax
	sall 	%cl,%eax		# num<<i
	movq 	%rbp,%rsp		# restoring the old stack pointer.
	popq 	%rbp			# restoring the old frame pointer.
	ret				# finish
.globl go 				# defining the label “go”.
.type go, @function 			# defining “go” as function.
go:
	pushq	%rbp          		# saving the old frame pointer.
	movq 	%rsp,%rbp		# creating the new frame pointer.
	movl 	$0,%r13d		# sum = 0
	xorl 	%r12d,%r12d		# i = 0
	movq 	%rdi,%r14		# set the first parameter to r14
.L1:
	xorq 	%r11,%r11		# r11 = 0
	leaq 	(%r14,%r12,4), %r11	# loading the address of the array in the index i to r11
	movl 	(%r11),%eax		# set A[i] to eax
	xorl 	%edx,%edx		# edx = 0
	movl 	$2,%ebx		# ebx = 2
	divl 	%ebx			# A[i] % 2
	cmpl 	$0,%edx		# compare A[i]%2:0
	je .L2				# if ==, go to L2
	addl 	(%r11),%r13d		# sum += A[i]
	jmp .L3			# go to i++ 
.L2:
	movl 	(%r11),%edi		# set A[i] as first parameter of even
	movl 	%r12d,%esi		# set i as second parameter of even
	call even			# num = even(A[i],i)
	addl 	%eax,%r13d		# sum += num
.L3:
	incl 	%r12d			# i++
	cmpl 	$10,%r12d		# compare i:10
	jl .L1				# if <, go to L1
	movl 	%r13d,%eax		# set sum as result value
	movq 	%rbp,%rsp		# restoring the old stack pointer.
	popq 	%rbp			# restoring the old frame pointer.
	ret				# finish
