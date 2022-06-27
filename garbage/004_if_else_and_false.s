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
  movl    $2, -20(%rbp)   # variable #tmp2
  movl    -20(%rbp), %eax     # variable #tmp2
  movl    %eax, -16(%rbp)     # variable b
  movl    $0, -28(%rbp)   # variable #tmp3
  movl    -28(%rbp), %eax     # variable #tmp3
  movl    %eax, -24(%rbp)     # variable c
  jmp BB1 # unconditional jump to true block
BB1:
  movl    $1, -36(%rbp)   # variable #tmp1
  movl    -8(%rbp), %eax    # variable a
  cmpl    -36(%rbp), %eax        # variable #tmp1
  sete    %al
  andb    $1, %al
  movzbl  %al, %eax
  movl    %eax, -40(%rbp)        # variable #tmp2
  movl    $1, -44(%rbp)   # variable #tmp3
  movl    -16(%rbp), %eax    # variable b
  cmpl    -44(%rbp), %eax        # variable #tmp3
  sete    %al
  andb    $1, %al
  movzbl  %al, %eax
  movl    %eax, -48(%rbp)        # variable #tmp4
  movl    -52(%rbp), %eax    # variable #tmp5
  cmpl    $0, %eax
  sete    %al
  andb    $1, %al
  movzbl  %al, %eax
  movl    %eax, -48(%rbp)        # variable #tmp4
  jne  BB4 # jump to false branch
BB2:
  movl    $1, -60(%rbp)   # variable #tmp1
  movl    -60(%rbp), %eax     # variable #tmp1
  movl    %eax, -24(%rbp)     # variable c
  jmp BB3 # unconditional jump to true block
BB3:
  jmp BB6 # unconditional jump to true block
BB4:
  jmp BB5 # unconditional jump to true block
BB5:
  movl    $5, -40(%rbp)   # variable #tmp1
  movl    -40(%rbp), %eax     # variable #tmp1
  movl    %eax, -24(%rbp)     # variable c
  jmp BB3 # unconditional jump to true block
BB6:
  movl    -24(%rbp), %eax
  jmp epilogue # unconditional jump to true block
