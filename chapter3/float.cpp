#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter a floating-point value: ";
    double n;
    cin >> n;
    cout << "n == " << n
         << "\nn + 1 = " << n + 1
         << "\nthree * n = " << 3 * n
         << "\nn squared = " << n * n
         << "\nsquare root of n = " << sqrt(n)
         << '\n';
}