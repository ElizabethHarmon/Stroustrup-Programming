#include "../std_lib_facilities.h"

int square(int x);

int main()
{
    int i = 0;
    while (i < 100)
    {
        cout << i << '\t' << square(i) << '\n';
        ++i;
    }
}

int square(int x)
{
    return x * x;
}

