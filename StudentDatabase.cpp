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

void print_instructions()
{
    cout << "Welcome to the student database.\n";
}

void set_person(Student *pStudent)
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

void get_person(Student *pStudent)
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

void clear_person(Student *pStudent)
{
    Student student;
    *pStudent = student;

    cout << "The student has been successfully cleared.\n";
}

void get_user_commands()
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
            set_person(pStudent);
        }
        else if (input == "get")
        {
            get_person(pStudent);
        }
        else if (input == "clear")
        {
            clear_person(pStudent);
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
    print_instructions();
    get_user_commands();

    return 0;
}
