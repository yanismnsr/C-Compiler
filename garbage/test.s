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
  movl    $4, -20(%rbp)   # variable #tmp1
  movl    -20(%rbp), %eax     # variable #tmp1
  movl    %eax, -8(%rbp)     # variable a
  movl    $7, -24(%rbp)   # variable #tmp2
  movl    -24(%rbp), %eax     # variable #tmp2
  movl    %eax, -12(%rbp)     # variable b
  movl    -8(%rbp), %eax        # variable a
  subl    -12(%rbp), %eax        # variable b
  movl    %eax, -28(%rbp)    #variable #tmp3
  movl    -28(%rbp), %eax     # variable #tmp3
  movl    %eax, -16(%rbp)     # variable c
  movl    -16(%rbp), %eax
