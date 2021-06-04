#include<iostream>
#include<stdlib.h>

using namespace std;

int checkprime(int n)
{
    if(n<=1)
        return 0;
    if(n<=3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(int i=6; i*i<=n; i+=6)
    {
        if(n%i==0 || n%(i+2)==0)
            return 0;
    }
    return 1;
}

int main()
{
    int n, flag;
    system("cls");
    cout << "Enter the number: ";
    cin >> n;
    flag=checkprime(n);
    switch(flag)
    {
        case 0: cout << "Number is not prime.";
                break;
        case 1: cout << "Number is prime.";
                break;
        default:cout << "Invalid input";
    }
    return 0;
}
