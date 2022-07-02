int nearestFibonacci (int a) {
    int b = 0, c = 1;
    while (c < a) {
        int tmp = c;
        c = c + b;
        b = tmp;
    }
    return c;
}

int main() {
    return nearestFibonacci(9);
}