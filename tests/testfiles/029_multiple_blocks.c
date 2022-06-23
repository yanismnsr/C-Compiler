int main () {

    // Block 1 starts
    int a, b, c;

    a = 0;
    b = 6;
    c = 36;
    // Block 1  ends

    {
        // Block 2 starts
        int a, b;
        a = 4;
        b = 6 + c;
        // Block 2 ends
    }

    // Block 3 starts
    return a + b + c;
    // Block 3 ends
}