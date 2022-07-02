int main() {
    int a = 6;
    int fact = a;
    while (a >= 1) {
        a = a - 1;
        fact = fact * a; 
    }
    return fact;
}