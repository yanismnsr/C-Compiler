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
  movl    $0, -12(%rbp)   # variable #tmp1
  movl    -12(%rbp), %eax     # variable #tmp1
  movl    %eax, -8(%rbp)     # variable a
  movl    $1, -20(%rbp)   # variable #tmp2
  movl    -20(%rbp), %eax     # variable #tmp2
  movl    %eax, -16(%rbp)     # variable b
  jmp BB1 # unconditional jump to true block
BB1:
  movl    -8(%rbp), %eax        # variable a
  cmpl    -16(%rbp), %eax        # variable b
  sete    %al
  andb    $1, %al
  movzbl  %al, %eax
  movl    %eax, -28(%rbp)        # variable #tmp1
  movl    -28(%rbp), %eax        # variable #tmp1
  cmpl    $0, %eax
  sete    %al
  andb    $1, %al
  movzbl  %al, %eax
  movl    %eax, -24(%rbp)        # variable #tmp3
  jne  BB3 # jump to false branch
BB2:
  movl    $1, -36(%rbp)   # variable #tmp1
  movl    -36(%rbp), %eax
  jmp epilogue # unconditional jump to true block
BB3:
   movq	%rbp, %rsp
   popq	%rbp
   retq
BB4:
  movl    $0, -32(%rbp)   # variable #tmp1
  movl    -32(%rbp), %eax
  jmp epilogue # unconditional jump to true block
