int main () {

    int a, b, c;

    a = 0;
    b = 6;
    c = 36;

    {
        int a, b;
        a = 4;
        b = 6 + c;
    }

    return a + b + c;
}