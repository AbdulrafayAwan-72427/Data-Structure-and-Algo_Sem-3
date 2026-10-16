#include<iostream>
using namespace std;
int main()
{
    int num=0;
    int table_of;
    int arr[num];
    int r=0;

    cout<<"Enter the number for table"<<endl;
    cin>>table_of;
    cout<<"Enter the number on which the table ends"<<endl;
    cin>>num;
    cout<<"the table of: "<<num<<" is "<<endl;

    for(int i=1;i<=num;i++){
        arr[r] = table_of*i;
        r++;
    }
        for(int i=0;i<num;i++){
            cout<<arr[i];
        }
}