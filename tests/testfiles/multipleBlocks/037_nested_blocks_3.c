int main() {
    int a = 1;
    {
        int b = 1 + a;
        a = b;
    }
    return a;
}