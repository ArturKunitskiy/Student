#include<iostream>
using namespace std;

class Student
{
	char* name;
	int age;
public:
	Student();
	Student(const char* n, int a);
	~Student();
	void Print();
	Student(const Student& obj);
	void Input();
};

Student::Student()
{
	name = nullptr;
	age = 0;
}
Student::Student(const char* n, int a)
{
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	age = a;
}
Student::~Student()
{
	cout << "Destructor\n";
	delete[] name;
	age = 0;
}
void Student::Print()
{
	cout << "Name: " << name << endl << "Age: " << age << endl;
}
void Student::Input()
{
	char buff[1000];
	cout << "Name: " << endl;
	cin >> buff;
	if (name != nullptr)
	{
		delete[] name;
	}

	name = new char[strlen(buff) + 1];
	strcpy_s(name, strlen(buff) + 1, buff);

	cout << "Age: " << endl;
	cin >> age;
}
Student::Student(const Student& obj)
{
	name = new char[strlen(obj.name) + 1];
	strcpy_s(name, strlen(obj.name) + 1, obj.name);
	age = obj.age;
	cout << "Copy constructor\n" << endl;
}

int main()
{
	Student a("Ivan ", 16);
	a.Print();
	Student b = a;

	b.Input();
	b.Print();
}