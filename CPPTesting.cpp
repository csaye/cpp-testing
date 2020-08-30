#include <iostream>

using namespace std;

class Person
{
    public:
        string name;
        int age;
    
    Person(string _name, int _age)
    {
        name = _name;
        age = _age;
    }
};

class Student
{
    public:
        string name;
        int age;
        char grade;
    
    Student(string _name, int _age, char _grade)
    {
        name = _name;
        age = _age;
        grade = _grade;
    }
};

void printInstructions()
{
    cout << "Welcome to the student database.";
}

void addPerson()
{
    string name;
    cout << "Please enter a name: ";
    cin >> name;

    int age;
    cout << "Please enter an age: ";
    cin >> age;

    char grade;
    cout << "Please enter a grade: ";
    cin >> grade;


    Student student(name, age, grade);
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
        else if (input == "add")
        {
            addPerson();
        }
    }
}

int main()
{
    printInstructions();
    getUserCommands();

    return 0;
}
