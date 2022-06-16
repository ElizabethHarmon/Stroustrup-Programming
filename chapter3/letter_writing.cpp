#include "../std_lib_facilities.h"

int main()
{
    // cout << "Please enter your first name (followed by 'enter'):\n";
    // string first_name;
    // cin >> first_name;
    // cout << "Hello, " << first_name << "!\n";

    cout << "Enter the name of the person you want to write to:\n";
    string first_name;
    cin >> first_name;
    cout << "Dear " << first_name << ",\n"
         << "   How are you? I am fine. I miss you.\n";

    cout << "\nEnter the name of another friend: ";
    string friend_name;
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " recently?";
    char friend_sex = '0';
    cout << "\nEnter 'm' if your friend is male or 'f' if female: ";
    cin >> friend_sex;
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.";
    else
        cout << "If you see " << friend_name << " please ask her to call me.";
    int age;
    cout << "\nEnter the age of your friend: ";
    cin >> age;
    cout << "I hear you had a birthday and you are " << age << " years old. ";
    if (age == 0 || age > 110)
        simple_error("You're kidding!");
    if (age < 12)
        cout << "Next year you will be " << age + 1 << ".\n";
    else if (age == 17)
        cout << "Next year you will be able to vote.\n";
    else if (age > 70)
        cout << "I hope you are enjoying retirement.\n";
    else
        cout << "I hope you had a great celebration!\n";
    cout << "Yours sincerely,\n\n\n"
         << "Beth Harmon\n";
}