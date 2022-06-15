# C-Compiler

This is a C compiler, inspired by gcc. For now, If generates X86 assembly code. ARM assembly support is coming soon.

## Usage
First, clone the project : 
SSH : 
```bash
git clone git@github.com:yanismnsr/C-Compiler.git
```
HTTPS : 
```bash
git clone https://github.com/yanismnsr/C-Compiler
```

Change the directory to the project :
```bash
cd C-Compiler/compiler
```

Compile the project : 
### M1 MacOS
```bash
./runmake_M1.sh
```

### Ubuntu
```bash
./runmake_ubuntu.sh
```

### Fedora
```bash
./runmake_fedora.sh
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