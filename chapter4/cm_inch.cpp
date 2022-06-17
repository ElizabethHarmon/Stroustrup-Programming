#include "../std_lib_facilities.h"

int main()
{
    constexpr double cm_per_inch = 2.54;
    double length;
    string unit;

    cout << "Please enter length followed by unit (cm or in):\n";
    cin >> length >> unit;

    if (unit == "in")
        cout << length << "in = " << length * cm_per_inch << "cm\n";
    else if (unit == "cm")
        cout << length << "cm = " << length / cm_per_inch << "in\n";
    else
        cout << "I'm sorry, I don't understand the unit " << unit << '\n';
}