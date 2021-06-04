#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

double power(double m,int n=2)
{
    double t;
    t=pow(m,n);
    return t;
}

int main()
{
    double num,ans;
    int p;
    system("cls");
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"\nEnter the power: ";
    cin>>p;
    if(p==0)
    {
        ans=power(num);
        cout<<"\nPower of "<<num<<" is "<<ans<<endl;
    }
    else
    {
        ans=power(num,p);
        cout<<"\nPower of "<<num<<" is "<<ans<<endl;
    }
    system("pause");
    return 0;
}
