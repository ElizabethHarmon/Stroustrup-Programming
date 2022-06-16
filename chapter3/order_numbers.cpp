#include "../std_lib_facilities.h"

int main()
{
    int i1;
    int i2;
    int i3;

    cout << "Enter three integers: ";
    cin >> i1 >> i2 >> i3;
    vector<int> v{i1, i2, i3};
    sort(v.begin(), v.end());

    cout << "Sorted:\n";
    for (auto x : v)
        cout << x << " ";
    cout << '\n';

    return 0;
}
