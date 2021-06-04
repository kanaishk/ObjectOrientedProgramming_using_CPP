#include<iostream>
#include<stdlib.h>

using namespace std;

class fibonacci
{
    private:
        unsigned long int f0, f1, fib;
    public:
        fibonacci()
        {
            f0=0;
            f1=1;
            fib=f0+f1;
        }
        fibonacci(fibonacci &ptr)
        {
            f0=ptr.f0;
            f1=ptr.f1;
            fib=ptr.fib;
        }
        void increment()
        {
            f0=f1;
            f1=fib;
            fib=f0+f1;
        }
        void display()
        {
            cout << fib << '\n';
        }
};

int main()
{
    fibonacci number;
    system("cls");
    for (int i=0; i<=10;i++)
    {
        number.display();
        number.increment();
    }
    system("pause");
    return 0;
}
