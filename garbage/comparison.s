.globl	_main
_main: 
  pushq	%rbp
  movq	%rsp, %rbp
  jmp BB0 # unconditional jump to true block
epilogue:
   movq	%rbp, %rsp
   popq	%rbp
   retq
BB0:
  movl    $1, -12(%rbp)
  movl    -12(%rbp), %eax
  movl    %eax, -8(%rbp) 	# a
  movl    $1, -20(%rbp)
  movl    -20(%rbp), %eax
  movl    %eax, -16(%rbp)	# b
  jmp BB1 # unconditional jump to true block
BB1:
  movl    -16(%rbp), %eax
  cmpl    -28(%rbp), %eax
  sete    %al
  andb    $1, %al
  movzbl  %al, %eax
  movl    %eax, -8(%rbp)
  je  BB3 # jump to false branch
BB2:
  movl    $2, -36(%rbp)
  movl    -36(%rbp), %eax
  movl    %eax, -8(%rbp)
  jmp BB3 # unconditional jump to true block
BB3:
  jmp BB4 # unconditional jump to true block
BB4:
  movl    -8(%rbp), %eax
  jmp epilogue # unconditional jump to true block
