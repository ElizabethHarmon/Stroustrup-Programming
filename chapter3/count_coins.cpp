#include "../std_lib_facilities.h"

int main()
{
    int pennies;
    int two_pence;
    int five_pence;
    int ten_pence;
    int twenty_pence;
    int fifty_pence;
    int pounds;
    double total;

    cout << "How many pennies do you have?: ";
    cin >> pennies;
    cout << "How many 2p coins do you have?: ";
    cin >> two_pence;
    cout << "How many 5p coins do you have?: ";
    cin >> five_pence;
    cout << "How many 10p coins do you have?: ";
    cin >> ten_pence;
    cout << "How many 20p coins do you have?: ";
    cin >> twenty_pence;
    cout << "How many 50p coins do you have?: ";
    cin >> fifty_pence;
    cout << "How many pound coins do you have?: ";
    cin >> pounds;

    total = 0.01 * pennies + 0.02 * two_pence + 0.05 * five_pence + 0.1 * ten_pence + 0.2 * twenty_pence + 0.5 * fifty_pence + pounds;
    cout << "\nThe value of all of your coins is £" << total << '\n';

    return 0;
}