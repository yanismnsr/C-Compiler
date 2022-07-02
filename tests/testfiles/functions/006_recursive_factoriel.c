#include <stdio.h>

int factorial(int a) {
    int result; 
    if (a == 1){
        result =  a;
    } else {
        result = a * factorial(a - 1);
    }
    return result;
}

int main() {
    return factorial(7);
}