#include "../std_lib_facilities.h"

struct Scores {
  int exact = 0;
  int near = 0;
};

void welcome();
vector<int> create_code();
string ask_for_guess();
bool check(string guess);
vector<int> s_to_v(string guess);
string v_to_s(vector<int> v);  // Convert vector to string
Scores tally_scores(vector<int> guesses, vector<int> secret_code);
bool print_response(struct Scores, int attempts, vector<int> v);

int main() {
  // Set number of allowed attempts
  int attempts = 8;
  // Welcome text
  welcome();
  // Create random secret code with unique digits from a vector of single digits
  vector<int> secret_code = create_code();

  while (attempts > 0) {
    // Ask user for their guess and return string
    string guess = ask_for_guess();
    // Check guess for length and duplicates
    bool valid = check(guess);

    if (!valid) {
      cout << "Input error: Please enter 4 unique digits\n";
      continue;
    }

    // Reduce number of attempts remaining
    --attempts;
    // Convert string to int vector
    vector<int> guesses = s_to_v(guess);
    // Tally exact and near scores
    struct Scores scores = tally_scores(guesses, secret_code);
    // Print response based on attempt
    bool win = print_response(scores, attempts, secret_code);
    if (win) {
      break;
    }
  }
  return 0;
}

void welcome() {
  cout << "Welcome to Bulls and Cows!\n"
       << "The computer will generate a secret code with 4 unique digits "
          "[0-9].\n"
       << "You have 8 attempts to guess the right digits in the right order.\n"
       << "Bull = right digit in the right position, Cow = right digit in the "
          "wrong position.\n\n";
}

vector<int> create_code() {
  array<int, 10> pick{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  srand(time(0));
  random_shuffle(pick.begin(), pick.end());
  vector<int> secret_code{};
  for (int i = 0; i < 4; ++i) {
    secret_code.push_back(pick[i]);
  }
  return secret_code;
}

string ask_for_guess() {
  string guess;
  cout << "What is your guess?: ";
  cin >> guess;
  return guess;
}

bool check(string guess) {
  bool valid = false;
  int size = 0;
  int duplicates = 0;

  for (int i = 0; guess[i] != '\0'; ++i) {
    size++;
  }

  for (int i = 0; i < size; ++i) {
    for (int j = i + 1; j < size; ++j)
      if (guess[i] == guess[j] && guess[i] != ' ')
        ++duplicates;
  }

  if (size == 4 && duplicates == 0) {
    valid = true;
  }
  return valid;
}

vector<int> s_to_v(string guess) {
  vector<int> guesses{};
  for (int i = 0; i < 4; ++i) {
    int num = (int)guess[i] - 48;
    guesses.push_back(num);
  }
  return guesses;
}

string v_to_s(vector<int> v) {
  string code;
  for (auto i : v) {
    code += to_string(i);
  }
  return code;
}

bool print_response(struct Scores scores, int attempts, vector<int> v) {
  bool win = false;
  if (scores.exact == 4) {
    cout << "You win with " << attempts << " guesses left!\n";
    win = true;
    return win;
  }

  if (attempts > 0) {
    cout << "Bulls:" << scores.exact << " Cows:" << scores.near << "  You have "
         << attempts << " guesses remaining.\n";
  } else {
    cout << "Bulls:" << scores.exact << " Cows:" << scores.near << '\n';
    cout << "Sorry, you used all your guesses.\n"
         << "The answer was " << v_to_s(v) << ".\n";
  }
  return win;
}

Scores tally_scores(vector<int> guesses, vector<int> secret_code) {
  struct Scores scores;
  int exact = 0;
  int near = 0;
  for (int i = 0; i < 4; ++i) {
    if (guesses[i] == secret_code[0] || guesses[i] == secret_code[1] ||
        guesses[i] == secret_code[2] || guesses[i] == secret_code[3]) {
      if (guesses[i] == secret_code[i]) {
        ++scores.exact;
      } else {
        ++scores.near;
      }
    }
  }
  return scores;
}