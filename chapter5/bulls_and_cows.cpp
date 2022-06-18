#include "../std_lib_facilities.h"
#include <string>
#include <vector>

struct Scores
{
    int exact = 0;
    int near = 0;
};

void welcome();
vector<int> create_code();
string ask_for_guess();
vector<int> s_to_v(string guess);
string v_to_s(vector<int> v); // Convert vector to string
Scores tally_scores(vector<int> guesses, vector<int> secret_code);
void print_response(struct Scores, int attempts, vector<int> v);

int main()
{
    int attempts = 8;    // Set number of allowed attempts

    welcome();
    vector<int> secret_code = create_code(); // Create random secret code with unique digits from a vector of single digits

    while (attempts > 0)
    {
        string guess = ask_for_guess();                            // Ask user for their guess and return string
        --attempts;                                                // Reduce number of attempts remaining
        vector<int> guesses = s_to_v(guess);                       // Convert string to int vector
        struct Scores scores = tally_scores(guesses, secret_code); // Tally exact and near scores
        print_response(scores, attempts, secret_code);             // Print response based on attempt
    }
}

void welcome()
{
    cout << "Welcome to Bulls and Cows!\n"
         << "The computer will generate a code with unique digits.\n"
         << "You have 8 attempts to guess the right digits in the right order.\n"
         << "Bull = right digit in the right position, Cow = right digit in the wrong position.\n";
}

vector<int> create_code()
{
    vector<int> pick{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    srand(time(0));
    random_shuffle(pick.begin(), pick.end());
    vector<int> secret_code{};
    for (int i = 0; i < 4; ++i)
        secret_code.push_back(pick[i]);
    return secret_code;
}

string ask_for_guess()
{
    string guess;
    cout << "What is your guess?: ";
    cin >> guess;
    return guess;
}

vector<int> s_to_v(string guess)
{
    vector<int> guesses{};
    for (int i = 0; i < 4; ++i)
    {
        int num = (int)guess[i] - 48;
        guesses.push_back(num);
    }
    return guesses;
}

string v_to_s(vector<int> v)
{
    string code;
    for (auto i : v)
        code += to_string(i);
    return code;
}

void print_response(struct Scores scores, int attempts, vector<int> v)
{
    if (scores.exact == 4)
    {
        cout << "You win with " << attempts << " guesses left!\n";
        return;
    }

    if (attempts > 0)
        cout << "Bulls:" << scores.exact << " Cows:" << scores.near << "  You have " << attempts << " guesses remaining.\n";
    else
    {
        cout << "Bulls:" << scores.exact << " Cows:" << scores.near << '\n';
        cout << "Sorry, you used all your guesses.\n"
             << "The answer was " << v_to_s(v) << ".\n";
    }
}

Scores tally_scores(vector<int> guesses, vector<int> secret_code)
{
    struct Scores scores;
    int exact = 0;
    int near = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (guesses[i] == secret_code[0] || guesses[i] == secret_code[1] || guesses[i] == secret_code[2] || guesses[i] == secret_code[3])
        {
            if (guesses[i] == secret_code[i])
                ++scores.exact;
            else
                ++scores.near;
        }
    }
    return scores;
}