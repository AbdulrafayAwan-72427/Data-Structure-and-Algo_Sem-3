#include<iostream>
using namespace std;
int main(){
    int size,sum;
    sum = 0;
    cout<<"Enter Size of array: ";
    cin>>size;
    int *arr = new int[size];
    int *p = arr;
    cout<<"Enter "<<size<<" Elements"<<endl;
    for(int i = 0; i <size; i++){
        cin>>*(p+i);
    }
    cout<<"User Entered: "<<endl;
    for(int i = 0;i<size;i++){
        cout<<*(p+i)<<endl;
        sum += *(p+i);
    }
    cout<<"Sum of Elements: "<<sum<<endl;
}