#include <iostream>

using namespace std;

class Person
{
    public:
        string name;
        int age;
    
    Person()
    {
        name = "";
        age = -1;
    }

    Person(string _name, int _age)
    {
        name = _name;
        age = _age;
    }
};

class Student : public Person
{
    public:
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
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    char grade;
    cout << "Please enter a grade: ";
    while (!(cin >> grade))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid grade. Please enter a single character: ";
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    Student student(name, age, grade);

    *pStudent = student;

    cout << "The student has been successfully set.\n";
}

void getPerson(Student *pStudent)
{
    Student student = *pStudent;

    if (student.name == "")
    {
        cout << "The student has not been set.\n";
        return;
    }

    cout << "The student currently stored has this information:\n";
    cout << "Name: " << student.name << "\n";
    cout << "Age: " << student.age << "\n";
    cout << "Grade: " << student.grade << "\n";
}

void clearPerson(Student *pStudent)
{
    Student student;
    *pStudent = student;

    cout << "The student has been successfully cleared.\n";
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
        else if (input == "get")
        {
            getPerson(pStudent);
        }
        else if (input == "clear")
        {
            clearPerson(pStudent);
        }
        else if (input == "help")
        {
            cout << "Commands:\n";
            cout << "quit, set, get, clear, help\n";
        }
        else
        {
            cout << "Invalid input. Type \"help\" for help.\n";
        }
        
    }
}

int main()
{
    printInstructions();
    getUserCommands();

    return 0;
}
