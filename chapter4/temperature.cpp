#include "../std_lib_facilities.h"

int main()
{
    vector<double> temps;
    cout << "Enter temperatures in Celsius:\n";
    for (double temp; cin >> temp;)
        temps.push_back(temp);

    double sum = 0;
    for (int x : temps)
        sum += x;
    cout << "The average temperature is " << sum / temps.size() << " degrees Celsius\n";

    sort(temps);
    if (temps.size() % 2 == 0)
    {
        double median_even = (temps[temps.size() / 2 - 1] + temps[temps.size() / 2]) / 2.0;
        cout << "The median temperature is " << median_even << " degrees Celsius\n";
    }

    else
    {
        double median_odd = temps[temps.size() / 2];
        cout << "The median temperature is " << median_odd << " degrees Celsius\n";
    }
}