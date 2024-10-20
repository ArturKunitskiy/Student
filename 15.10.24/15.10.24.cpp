#include<iostream>
using namespace std;

class MyArray
{
    int* ptr;
    int size;
public:
    MyArray()
    {
        ptr = nullptr;
        size = 0;
    }

    MyArray(int s)
    {
        size = s;
        ptr = new int[size] {0};

    }

    ~MyArray()
    {
        cout << "destructor\n";
        delete[] ptr;
    }

    void Input()
    {
        for (int i = 0; i < size; i++)
        {
            ptr[i] = i + i;
        }
    }

    void Print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << ptr[i] << "\t";
        }
        cout << endl;
    }

    MyArray(const MyArray& obj) // copy constructor 
    {
        size = obj.size;
        ptr = new int[size];
        for (int i = 0; i < size; i++)
        {
            ptr[i] = obj.ptr[i];
        }
        cout << "Copy constructor\n";

    }
};

int main()
{
    MyArray obj(10);
    obj.Input();
    obj.Print();

    MyArray obj2 = obj;


}