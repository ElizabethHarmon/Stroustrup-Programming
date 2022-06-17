#include "../std_lib_facilities.h"

int main()
{
    vector<string> words;
    for (string temp; cin >> temp;)
        words.push_back(temp);
    cout << "\nNumber of words entered: " << words.size() << "\n\n";

    sort(words);
    int unique;
    for (int i = 0; i < words.size(); ++i)
        if (i == 0 || words[i - 1] != words[i])
        {
            ++unique;
            cout << words[i] << '\n';
        }
    cout << "\nNumber of unique words: " << unique << "\n\n";
}