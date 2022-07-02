#include <stdio.h>

int factorial(int a) {
    int result; 
    if (a == 1){
        result =  a;
    } else {
        putchar(48 + a);
        result = a * factorial(a - 1);
    }
    return result;
}

int main() {
    return factorial(7);
}