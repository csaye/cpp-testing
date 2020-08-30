#include <iostream>

using namespace std;

void printInstructions()
{
    cout << "Welcome. Please enter people into the database with their name, age, and occupation." << endl;
}

void getUserCommands()
{
    string input;
    bool running = true;

    while (running)
    {
        cin >> input;

        if (input == "quit")
        {
            running = false;
        }
    }
}

int main()
{
    printInstructions();
    getUserCommands();

    return 0;
}
