#include<iostream>
#include<stdlib.h>

using namespace std;

class class1;
class class2;

class class1
{
    private:
        int a;
    public:
        void input()
        {
            cin >> a;
        }
        friend bool findLargest(class1 x, class2 y);
};

class class2
{
    private:
        int b;
    public:
        void input()
        {
            cin >> b;
        }
        friend bool findLargest(class1 x, class2 y);
};

bool findLargest(class1 x, class2 y)
{
    return (x.a > y.b) ? true : false;
}

int main()
{
    system("cls");
    class1 x;
    class2 y;
    cout << "Enter the first value: ";
    x.input();
    cout << "Enter the second value: ";
    y.input();
    if(findLargest(x,y))
    {
        cout << "First is bigger.";
    }
    else
    {
        cout << "Second is bigger.";
    }
    cout << "\n\n";
    system("pause");
    return 0;
}
