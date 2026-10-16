#include<iostream>
using namespace std;
int main()
{
    int w,x,y,z;
    char input;
    cout<<"Enter 4 Numbers."<<endl;
    cin>>w>>x>>y>>z;
    cout<<"Enter a for Addition "<< '\t'<<" s for Subraction "<< '\t' <<" m for Multiplicaton "<<endl;
    cin>>input;
    switch(input){
        case'a':
        case'A':
            cout<<"Addition of Numbers is: "<<w+x+y+z<<endl;
            break;
        case's':
        case'S':
            cout<<"Subtraction of Numbers is: "<<w-x-y-z<<endl;
            break;
        case'm':
        case'M':
            cout<<"Multiplication of Numbers is: "<<w*x*y*z<<endl;
            break;
        default:
            cout<<"Invalid input"<<endl;
    
    }
}