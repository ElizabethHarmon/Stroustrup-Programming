#include "../std_lib_facilities.h"

int square(int x);

int main()
{
    int i = 0;
    for (int i = 0; i < 100; ++i)
        cout << i << '\t' << square(i) << '\n';
}

int square(int x)
{
    return x * x;
}
