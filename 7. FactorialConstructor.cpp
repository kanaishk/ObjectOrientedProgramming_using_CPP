#include<iostream>
#include<stdlib.h>

using namespace std;

class factorial
{
    private:
        int n;
        int f;
        fact()
        {
            f=1;
            for(int i=1; i<=n; i++)
            {
                f=f*i;
            }
        }
    public:
        factorial()
        {
            n=0;
            f=1;
        }
        factorial(int val)
        {
            n=val;
            f=1;
            for(int i=1; i<=n; i++)
            {
                f=f*i;
            }
        }
        void input()
        {
            cout << "Enter number: ";
            cin >> n;
            fact();
        }
        void display()
        {
            cout << "Factorial of " << n << " is " << f << endl;
        }
};

int main()
{
    factorial f(7);
    system("cls");
    f.display();
    system("pause");
    return 0;
}
