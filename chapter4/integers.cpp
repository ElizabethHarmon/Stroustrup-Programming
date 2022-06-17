#include "../std_lib_facilities.h"

int main()
{
    int a = 0;
    int b = 0;
    cout << "Please enter two integers\n";
    cin >> a >> b;

    if (a < b)
        cout << "Max value is " << b << '\n';
    else
        cout << "Max value is " << a << '\n';
}
