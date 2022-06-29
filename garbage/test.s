.globl	function
function: 
  pushq	%rbp
  movq	%rsp, %rbp
  subq    $4, %rsp
function_prologue:
  jmp function_BB0 # unconditional jump to true block
function_epilogue:
   movq	%rbp, %rsp
   popq	%rbp
   retq
function_BB0:
  movl    $3, -8(%rbp)   # variable #tmp1
  movl    -8(%rbp), %eax
  jmp function_epilogue # unconditional jump to true block
.globl	_main
_main: 
  pushq	%rbp
  movq	%rsp, %rbp
  subq    $4, %rsp
_main_prologue:
  jmp _main_BB0 # unconditional jump to true block
_main_epilogue:
   movq	%rbp, %rsp
   popq	%rbp
   retq
_main_BB0:
  jmp _main_BB1 # unconditional jump to true block
_main_BB1:
  call function
  movl    %eax, -8(%rbp)      # variable #tmp1
  movl    -8(%rbp), %eax
  jmp _main_epilogue # unconditional jump to true block
