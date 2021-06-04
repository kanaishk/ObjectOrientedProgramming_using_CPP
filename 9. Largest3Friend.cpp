#include<iostream>
#include<stdlib.h>

using namespace std;

class Test
{
    private:
        int x, y, z;
    public:
        void input()
        {
            cout << "Enter three numbers:\n";
            cin >> x >> y >> z;
        }
        friend void find(Test t);
};

void find(Test t)
{
    if (t.x > t.y && t.x > t.z)
    {
        cout << "Largest is: " << t.x;
    }
    else if (t.y > t.z)
    {
        cout << "Largest is: " << t.y;
    }
    else
    {
        cout << "Largest is: " << t.z;
    }
}

int main()
{
    Test t;
    system("cls");
    t.input();
    find(t);
    cout << "\n\n";
    system("pause");
    return 0;
}
