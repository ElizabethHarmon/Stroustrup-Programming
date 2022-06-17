#include "../std_lib_facilities.h"

int main()
{
    cout << "Welcome to Guess-The-Number!\n";

    cout << "Enter the maximum number you want to guess: ";
    int max;
    cin >> max;

    srand(time(0));
    int number = rand() % max + 1;

    int guess;
    int tries = 0;

    while (true)
    {
        cout << "Enter a number: ";
        cin >> guess;

        if (guess == number)
        {
            ++tries;
            if (tries > 1)
                cout << "You guessed the right number in " << tries << " tries\n";
            else
                cout << "You guessed the right number in " << tries << " try\n";
            break;
        }
        else if (guess < number)
        {
            ++tries;
            cout << "Guess a higher number!\n";
        }

        else
        {
            ++tries;
            cout << "Guess a lower number!\n";
        }
    }
}
