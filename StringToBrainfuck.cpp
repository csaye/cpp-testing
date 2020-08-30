#include <iostream>

std::string getUserString()
{
    std::string input;
    std::cout << "Please enter a string to convert: ";
    std::cin >> input;
    return input;
}

void append(std::string &str, int num)
{
    if (num > 0)
    {
        for (int i = 0; i < num; i++)
        {
            str += "+";
        }
    }
    else if (num < 0)
    {
        for (int i = 0; i > num; i--)
        {
            str += "-";
        }
    }
    
    str += ".";
}

std::string convertUserString(std::string input)
{
    std::string output = "";
    int currChar = 0;

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        append(output, ch - currChar);
        currChar = ch;
    }

    return output;
}

int main()
{
    std::string input = getUserString();
    std::string output = convertUserString(input);
    std::cout << "String \"" << input << "\" in Brainfuck is:\n" << output << "\n";
}
