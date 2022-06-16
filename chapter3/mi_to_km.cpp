#include "../std_lib_facilities.h"

int main()
{
    double miles;
    double km;
    cout << "Enter number of miles: ";
    cin >> miles;
    km = miles * 1.609;
    cout << miles << " miles is equal to " << km << " kilometers.\n";
    return 0;
}
