#include<iostream>
#include<stdlib.h>

using namespace std;

class time
{
    private:
        int hour;
        int mint;
        int sec;
    public:
        time()
        {
            hour=0;
            mint=0;
            sec=0;
        }
        time(int h, int m, int s)
        {
            hour=h;
            mint=m;
            sec=s;
        }
        void input()
        {
            cout << "Hour: ";
            cin >> hour;
            cout << "Minute: ";
            cin >> mint;
            while(mint>=60 || mint<0)
            {
                cout << "Invalid Input...! Max 59. Try again: ";
                cin >> mint;
            }
            cout << "Second: ";
            cin >> sec;
            while(sec>=60 || sec<0)
            {
                cout << "Invalid Input...! Max 59. Try again: ";
                cin >> sec;
            }
        }
        void output()
        {
            cout << hour << " : " << mint << " : " << sec;
        }
        time operator +(const time &obj)
        {
            time temp;
            temp.sec=sec+obj.sec;
            if(temp.sec>=60)
            {
                temp.mint+=1;
                temp.sec-=60;
            }
            temp.mint+=mint+obj.mint;
            if(temp.mint>=60)
            {
                temp.hour+=1;
                temp.mint-=60;
            }
            temp.hour+=hour+obj.hour;
            return temp;
        }
};

time add(time a, time b)
{
    return a+b;
}

int main()
{
    time t1, t2, t3;
    system("cls");
    cout << "T1:\n";
    t1.input();
    cout << "T2:\n";
    t2.input();
    t3=add(t1, t2);
    system("cls");
    cout << "T1: ";
    t1.output();
    cout << "\n";
    cout << "T2: ";
    t2.output();
    cout << "\n";
    cout << "T3: ";
    t3.output();
    cout << "\n";
    system("pause");
    return 0;
}
