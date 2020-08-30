#include <iostream>

using namespace std;

string getUserInput()
{
    string input;
    cin >> input;
    return input;
}

void printUserInput(string input)
{
    cout << input;
}

int main()
{
    printUserInput(getUserInput());

    return 0;
}
