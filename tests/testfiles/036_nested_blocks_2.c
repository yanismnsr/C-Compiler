int main () {
    int a = 0;
    {
        int a;
        a = a + a;
    }
    return a;
}