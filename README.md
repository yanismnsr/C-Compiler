# C-Compiler

This is a C compiler, inspired by gcc. For now, If generates X86 assembly code. ARM assembly support is coming soon.

## Compile the project
### Clone 
SSH : 
```bash
git clone git@github.com:yanismnsr/C-Compiler.git
```
HTTPS : 
```bash
git clone https://github.com/yanismnsr/C-Compiler
```

### Compile
Go to the compiler directory
```bash
cd C-Compiler/compiler
```

#### Apple Silicon
```bash
./runmake_M1.sh
```

#### Ubuntu
```bash
./runmake_ubuntu.sh
```

#### Fedora
```bash
./runmake_fedora.sh
```

## Usage
Always in the "compiler" directory : 
```bash
./ifcc <path to your program>
```

This will show the assembly directly on the console.

If you with to put the output in a file, simply redirect the standard output in bash :
```bash
./ifcc <path to your program> > executable
```

## Run tests
A list of test scenarios are already written in the directory `tests/testfiles` of the project. To run them, run the following commands : 

:warning: **If you are on Apple Silicon**: make sure you have rosetta2 and run your terminal on X86 mode. Alternatively, you can run `arch -x86_64 zsh` to open a terminal in X86 architecture.
```bash
cd tests
./ifcc-test.py testfiles
```

## Features 
For now, it can compile basic programs with the following : 
* Variable declaration
* Affectation of constants to variables 
* Affectation of variable to variable
* Evaluation of an arithmetic expression with respect of priorities
    * Addition
    * Substraction
    * Multiplication
    * Division
* Evaluation of an expessions with "-" and "+" unary operators
* Evaluation of an expression with parenthesis

Moreover, the compiler is also capable of displaying warnings in the following cases : 
* If a variable is declared but never used

Finally, it also makes the following verifications :
* That evey used variable is declared


## Coming features
* Include intermediate representation (IR), to be able to support multiple target ISAs (Instruction Set Architecture) for the generated assembly 
* ARM assembly support
* If-then-else
* For and while loops
* Function calls

# Our team members
* [Nikita TEREKHOV](https://github.com/neeeekitos)
* [Louise PIETROPAOLI](https://github.com/LouisePietropaoli)
* [Laetitia GETTI](https://github.com/lgetti)
* [Gaëlle FERREIRA](https://github.com/Galiixy)
* [Lina ZOUIRI](https://github.com/nzlar)
* [Yanis MANSOUR](https://github.com/yanismnsr) 