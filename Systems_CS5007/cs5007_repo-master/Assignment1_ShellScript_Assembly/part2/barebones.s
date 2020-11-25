# Build an executable using the following:
#
# clang barebones.s -o barebones  # clang is another compiler like gcc
#
.text
_barebones:

.data
	
.globl main

main:
					# (1) What are we setting up here?
					# Ans: The current value of the register
	pushq %rbp			# is being pushed onto the stack, so
					# that the register can be used.
	movq  %rsp, %rbp		#

					# (2) What is going on here
					# Ans: Data is being moved into
	movq $1, %rax			# the registers.
	movq $1, %rdi			#
	leaq .hello.str,%rsi		#


					# (3) What is syscall? We did not talk about this
					# in class.
					# Ans: The syscall instruction transfers control to
					# the operating system which then performs the
					# requested service. Then control (usually) returns
					# to the program.
	syscall				# Which syscall is being run?
					# Ans: brk 

					# (4) What would another option be instead of 
					# using a syscall to achieve this?
					# Ans: int 0x80 could be used instead
					# of syscall
					# and malloc has similar functionality
					# to brk

	movq	$60, %rax		# (5) We are again setting up another syscall
	movq	$0, %rdi		# What command is it?
					# Ans: write
	syscall

	popq %rbp			# (Note we do not really need
					# this command here after the syscall)

.hello.str:
	.string "Hello World!\n"
	.size	.hello.str,13		# (6) Why is there a 13 here?
					# Ans:	it is the length of the string
