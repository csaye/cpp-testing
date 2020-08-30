#include <iostream>

using namespace std;

void print_instructions()
{
    cout << "I have a number between 1 and 100. Try to guess it.\n";
}

void get_user_input()
{
    bool numberGuessed = false;
    int num = rand() % 100 + 1;
    int input;
    int tries = 0;

    while (!numberGuessed)
    {   
        tries++;

        cout << "Please enter an integer: ";
        while (!(cin >> input))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter an integer: ";
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (input == num)
        {
            cout << "You guessed the number in " << tries << " tries.\n";
            numberGuessed = true;
        }
        else if (input < num)
        {
            cout << "Guess is too low.\n";
        }
        else if (input > num)
        {
            cout << "Guess is too high.\n";
        }
    }
}

int main()
{
    print_instructions();
    get_user_input();

    return 0;
}
