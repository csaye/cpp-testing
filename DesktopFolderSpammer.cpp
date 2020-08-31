#include <iostream>
#include <fstream>

void createDesktopFolder(int count std::string username)
{
    for (int i = 0; i < count; i++)
    {
        std::ofstream file("Users/" + username + "/Desktop/pranked" + std::to_string(i) + ".txt");
        file << "you just got pranked";
        file.close();
    }
}

int main()
{
    createDesktopFolder(3, "HomeiMac");
}
