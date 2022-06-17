#include "../std_lib_facilities.h"

int main()
{
    constexpr double cm_per_inch = 2.54;
    double length;
    char unit;

    cout << "Please enter length followed by unit (c or i):\n";
    cin >> length >> unit;

    switch (unit)
    {
    case 'i':
        cout << length << "in = " << length * cm_per_inch << "cm\n";
        break;
    case 'c':
        cout << length << "cm = " << length / cm_per_inch << "in\n";
        break;
    default:
        cout << "I'm sorry, I don't understand the unit " << unit << '\n';
        break;
    }
}