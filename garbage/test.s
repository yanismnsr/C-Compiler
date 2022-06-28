returning #tmp3
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
  movl    $1, -12(%rbp)   # variable #tmp1
  movl    -12(%rbp), %eax     # variable #tmp1
  movl    %eax, -8(%rbp)     # variable a
  movl    $3, -20(%rbp)   # variable #tmp2
  movl    -20(%rbp), %eax     # variable #tmp2
  movl    %eax, -16(%rbp)     # variable b
  movl    -8(%rbp), %eax        # variable a
  xorl    -16(%rbp), %eax        # variable b
  movl    %eax, -24(%rbp)    #variable #tmp3
  movl    -24(%rbp), %eax
  jmp epilogue # unconditional jump to true block
