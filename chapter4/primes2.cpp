#include "../std_lib_facilities.h"

int main()
{
    int min, max;
    cout << "Enter min and max numbers: ";
    cin >> min >> max; // In real program, I would swap min and max if user inputted values where min > max
    cout << "The Prime numbers between the numbers " << min << " and " << max << " are:\n";
    int number = min;
    while (number < max + 1)
    {
        bool prime = true;
        for (int i = 2; i <= number / 2; ++i)
        {
            if (number % i == 0)
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