int main() {
    int a = 1;
    int b = 2;
    if (a == b) {
        a = 2;
        b = 4;
    } else {
        a = 3;
    }
    return a + b;
}