#include <iostream>

std::string promptUser()
{
    std::cout << "Please enter a random string: ";
    std::string input;
    std::cin >> input;
    return input;
}

int generateRandom(std::string randomString)
{
    int randomNumber = 1;

    for (int i = 0; i < 8; i++)
    {
        if (randomString.length() - 1 < i) break;

        if (i % 2 == 0)
        {
            randomNumber *= randomString[i];
        }
        else
        {
            randomNumber += randomString[i];
        }
    }

    return randomNumber % 100;
}

void printRandomNumber(int randomNumber)
{
    std::cout << "The random number between 0 and 99 is: \n" << randomNumber << "\n";
}

int main()
{
    std::string randomString = promptUser();
    int randomNumber = generateRandom(randomString);
    printRandomNumber(randomNumber);
}
