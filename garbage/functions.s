.globl	factorial
factorial: 
  pushq	%rbp
  movq	%rsp, %rbp
  subq    $48, %rsp
  movl %edi, -4(%rbp)        # getting parameter a
factorial_prologue:
  jmp factorial_BB0 # unconditional jump to true block
factorial_epilogue:
   movq	%rbp, %rsp
   popq	%rbp
   retq
factorial_BB0:
  jmp factorial_BB1ifbb # unconditional jump to true block
factorial_BB1ifbb:
  movl    $1, -20(%rbp)   # variable #tmp1
  movl    -4(%rbp), %eax        # variable a
  cmpl    -20(%rbp), %eax        # variable #tmp1
  sete    %al
  movzbl  %al, %eax
  movl    %eax, -24(%rbp)        # variable #tmp2
  movl    -24(%rbp), %eax        # variable #tmp2
  cmpl    $0, %eax
  sete    %al
  movzbl  %al, %eax
  movl    %eax, -28(%rbp)        # variable #tmp3
  je  factorial_BB3falseBb # jump to false branch
factorial_BB2trueBb:
  movl    -4(%rbp), %eax     # variable a
  movl    %eax, -12(%rbp)     # variable result
  jmp factorial_BB4defaultBb # unconditional jump to true block
factorial_BB3falseBb:
  movl    $48, -24(%rbp)   # variable #tmp2
  movl    -24(%rbp), %eax        # variable #tmp2
  addl    -4(%rbp), %eax        # variable a
  movl    %eax, -28(%rbp)    #variable #tmp3
  movl	-28(%rbp), %edi	# put param into register
  call _putchar
  movl    %eax, -20(%rbp)      # variable #tmp1
  movl    $1, -36(%rbp)   # variable #tmp5
  movl    -4(%rbp), %eax        # variable a
  subl    -36(%rbp), %eax        # variable #tmp5
  movl    %eax, -40(%rbp)    #variable #tmp6
  movl	-40(%rbp), %edi	# put param into register
  call factorial
  movl    %eax, -32(%rbp)      # variable #tmp4
  movl    -4(%rbp), %eax        # variable a
  imull    -32(%rbp), %eax        # variable #tmp4
  movl    %eax, -44(%rbp)        #variable #tmp7
  movl    -44(%rbp), %eax     # variable #tmp7
  movl    %eax, -12(%rbp)     # variable result
  jmp factorial_BB4defaultBb # unconditional jump to true block
factorial_BB4defaultBb:
  movl    -12(%rbp), %eax
  jmp factorial_epilogue # unconditional jump to true block
.globl	_main
_main: 
  pushq	%rbp
  movq	%rsp, %rbp
  subq    $8, %rsp
_main_prologue:
  jmp _main_BB0 # unconditional jump to true block
_main_epilogue:
   movq	%rbp, %rsp
   popq	%rbp
   retq
_main_BB0:
  jmp _main_BB1 # unconditional jump to true block
_main_BB1:
  movl    $7, -12(%rbp)   # variable #tmp2
  movl	-12(%rbp), %edi	# put param into register
  call factorial
  movl    %eax, -8(%rbp)      # variable #tmp1
  movl    -8(%rbp), %eax
  jmp _main_epilogue # unconditional jump to true block
