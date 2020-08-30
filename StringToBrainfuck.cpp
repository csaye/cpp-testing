#include <iostream>

std::string getUserString()
{
    std::string input;
    std::cout << "Please enter a string to convert: ";
    std::cin >> input;
    return input;
}

std::string convertUserString(std::string input)
{
    return NULL;
}

int main()
{
    std::string input = getUserString();
    std::string output = convertUserString(input);
    std::cout << input << " in Brainfuck is " << output;
}
