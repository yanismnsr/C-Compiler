int main () {
    {return 4;}
    {
        {return 2;}
        return 3;
    }
    {return 1;}
    return 0;
}