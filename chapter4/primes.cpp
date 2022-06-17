#include "../std_lib_facilities.h"

int main()
{
    cout << "The Prime numbers between the number 1 and 100 are:\n";
    int number = 2;
    while (number < 100)
    {
        bool prime = true;
        for (int x = 2; x <= number / 2; ++x)
        {
            if (number % x == 0)
            {
                prime = false;
                break;
            }
        }
        if (prime == true)
            cout << number << " ";
        ++number;
    }
    cout << '\n';
}