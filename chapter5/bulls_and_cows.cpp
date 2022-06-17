#include "../std_lib_facilities.h"
#include <string>
#include <vector>

struct Scores
{
    int exact = 0;
    int near = 0;
};

vector<int> create_code();
vector<int> s_to_v(string guess);
string v_to_s(vector<int> v); // Convert vector to string
Scores tally_scores(vector<int> guesses, vector<int> secret_code);
void print_out(struct Scores, int guess_count, vector<int> v);

int main()
{
    int guess_count = 8; // Set number of allowed attempts

    vector<int> secret_code = create_code(); // Create random secret code with unique digits from a vector of single digits
    
    string guess;
    while (guess_count > 0)
    {
        cout << "What is your guess?: ";
        cin >> guess;
        --guess_count;
        vector<int> guesses = s_to_v(guess); // Convert string to int vector
        struct Scores scores = tally_scores(guesses, secret_code); // Tally exact and near scores
        print_out(scores, guess_count, secret_code);
    }
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

void print_out(struct Scores scores, int guess_count, vector<int> v)
{
    if (scores.exact == 4)
    {
        cout << "You win with " << guess_count << " guesses left!\n";
        return;
    }

    if (guess_count > 0)
        cout << "A" << scores.exact << "B" << scores.near << " You have " << guess_count << " guesses remaining.\n";
    else
    {
        cout << "A" << scores.exact << "B" << scores.near << '\n';
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