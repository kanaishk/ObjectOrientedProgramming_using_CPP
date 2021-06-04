#include<iostream>
#include<stdlib.h>

using namespace std;

class complex
{
    private:
        int real;
        int img;
    public:
        complex()
        {
            real=0;
            img=0;
        }
        complex(int a)
        {
            real=a;
            img=a;
        }
        complex(int a, int b)
        {
            real=a;
            img=b;
        }
        complex(const complex &obj)
        {
            real=obj.real;
            img=obj.img;
        }
        int return_real() const
        {
            return real;
        }
        int return_img() const
        {
            return img;
        }
        void input()
        {
            cout << "Real: ";
            cin >> real;
            cout << "Imaginary: ";
            cin >> img;
        }
        void display()
        {
            cout << real << " + " << img << "i";
        }
        complex operator +(const complex &obj)
        {
            complex res;
            res.real=real+obj.real;
            res.img=img+obj.img;
            return res;
        }
};

int main()
{
    complex c1, c2(1), c3(3,4);
    system("cls");
    c1=c2+c3;
    cout << "First:\t\t";
    c2.display();
    cout << "\nSecond:\t\t";
    c3.display();
    cout << "\nAddition:\t";
    c1.display();
    return 0;
}
