#include <iostream>

using namespace std;

int main()
{
    for (int i = 1; i <= 100; i++)
    {
        string str = "";

        if (i % 5 == 0) str += "Fizz";
        if (i % 7 == 0) str += "Buzz";

        if (str == "") str += to_string(i);

        cout << str << "\n";
    }

    return 0;
}