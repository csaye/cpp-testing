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
    
    Student()
    {
        name = "";
        age = -1;
        grade = ' ';
    }

    Student(string _name, int _age, char _grade)
    {
        name = _name;
        age = _age;
        grade = _grade;
    }
};

void printInstructions()
{
    cout << "Welcome to the student database.\n";
}

void setPerson(Student *pStudent)
{
    string name;
    cout << "Please enter a name: ";
    cin >> name;

    int age;
    cout << "Please enter an age: ";
    while (!(cin >> age))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid age. Please enter an integer: ";
    }
    cin.clear();

    char grade;
    cout << "Please enter a grade: ";
    while (!(cin >> grade))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid grade. Please enter a single character: ";
    }
    cin.clear();

    Student student(name, age, grade);

    *pStudent = student;

    cout << "The student has been successfully set.\n";
}

void removePerson(Student *pStudent)
{
    Student student;
    *pStudent = student;

    cout << "The student has been successfully removed.\n";
}

void getPerson(Student *pStudent)
{
    Student student = *pStudent;

    cout << "The student currently stored has this information:\n";
    cout << "Name: " << student.name << "\n";
    cout << "Age: " << student.age << "\n";
    cout << "Grade: " << student.grade << "\n";
}

void getUserCommands()
{
    string input;
    bool running = true;
    Student student;
    Student *pStudent = &student;

    while (running)
    {
        cout << "> ";
        cin >> input;

        if (input == "quit")
        {
            running = false;
        }
        else if (input == "set")
        {
            setPerson(pStudent);
        }
        else if (input == "remove")
        {
            removePerson(pStudent);
        }
        else if (input == "get")
        {
            getPerson(pStudent);
        }
    }
}

int main()
{
    printInstructions();
    getUserCommands();

    return 0;
}
