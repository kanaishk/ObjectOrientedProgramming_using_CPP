#include<iostream>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265

using namespace std;

// Area of Triangle
float area(float side1, float side2, float side3)
{
    float s=(side1+side2+side3)/2;
    return sqrt(s*(s-side1)*(s-side2)*(s-side3));
}

// Area of square
float area(float radius)
{
    return PI*radius*radius;
}

// Area of rectangle
float area(float length, float breadth)
{
    return length*breadth;
}

int main()
{
    int ch;
    float a, b, c;
    do
    {
        system("cls");
        cout << "\t\t\t\tArea Calculator\n";
        cout << "What do you want to do?\n";
        cout << " 1. Circle\n";
        cout << " 2. Rectangle\n";
        cout << " 3. Triangle\n";
        cout << " 4. Exit\n";
        cout << "Enter your choice(1-4): ";
        cin >> ch;
        cout << "\n\n";
        switch(ch)
        {
            case 1: cout << "Enter Radius: ";
                    cin >> a;
                    cout << "It's area is " << area(a) << " unit squared";
                    break;
            case 2: cout << "Enter Lenght: ";
                    cin >> a;
                    cout << "Enter Breadth: ";
                    cin >> b;
                    cout << "It's area is " << area(a, b) << " unit squared";
                    break;
            case 3: cout << "Enter Side 1: ";
                    cin >> a;
                    cout << "Enter Side 2: ";
                    cin >> b;
                    cout << "Enter Side 3: ";
                    cin >> c;
                    cout << "It's area is " << area(a, b, c) << " unit squared";
                    break;
            case 4: ch=4;
                    break;
            default:cout << "Invalid input...!";
        }
        cout << "\n\n";
        system("pause");
    }while(ch!=4);
    return 0;
}
