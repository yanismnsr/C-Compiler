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
  movl    $0, -20(%rbp)
  movl    -20(%rbp), %eax
  movl    %eax, -8(%rbp)
  movl    $6, -24(%rbp)
  movl    -24(%rbp), %eax
  movl    %eax, -12(%rbp)
  movl    $36, -28(%rbp)
  movl    -28(%rbp), %eax
  movl    %eax, -16(%rbp)
  jmp BB1 # unconditional jump to true block
BB1:
  movl    $4, -44(%rbp)
  movl    -44(%rbp), %eax
  movl    %eax, -36(%rbp)
  movl    $6, -48(%rbp)
  movl    -48(%rbp), %eax
  addl    -16(%rbp), %eax
  movl    %eax, -52(%rbp)
  movl    -52(%rbp), %eax
  movl    %eax, -40(%rbp)
  jmp BB2 # unconditional jump to true block
BB2:
  movl    -8(%rbp), %eax
  addl    -12(%rbp), %eax
  movl    %eax, -36(%rbp)
  movl    -36(%rbp), %eax
  addl    -16(%rbp), %eax
  movl    %eax, -40(%rbp)
  movl    -40(%rbp), %eax
  jmp epilogue # unconditional jump to true block
