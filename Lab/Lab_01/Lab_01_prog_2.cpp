#include<iostream>
using namespace std;
int main()
{
    int num;
    cout<<"Enter Number for Checking if Even or Odd"<<endl;
    cin>>num;
    if (num%2==0 && num>0)
        cout<<num<<" is Even.";
    else if(num==0)
        cout<<"Number Should not be 0"<<endl;
    else
        cout<<num<<" Is Odd"<<endl;
}