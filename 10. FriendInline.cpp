#include<iostream>
#include<stdlib.h>

using namespace std;

class trial
{
    private:
        int x;
    public:
        inline void getdata();
        friend void display(class trial);
};

inline void trial::getdata()
{
    cout << "Enter a value of x: ";
    cin >> x;
}

inline void display(class trial a)
{
    cout << "Number is: " << a.x;
    cout << endl;
}

int main()
{
    trial obj;
    system("cls");
    obj.getdata();
    cout << "Accessing the private-data by non-member function\n";

    display(obj);
    system("pause");
    return 0;
}
