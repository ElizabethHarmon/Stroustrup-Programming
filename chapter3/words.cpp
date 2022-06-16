#include "../std_lib_facilities.h"

int main()
{
    cout << "Enter two words: \n";
    string first;
    string second;
    cin >> first >> second;

    if (first == second) cout << "The words are the same!\n";
    else if (first < second) 
        cout << first << " comes before " << second << '\n';
    else 
        cout << second << " comes before " << first << '\n';
}