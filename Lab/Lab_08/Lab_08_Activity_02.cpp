#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter Size of array: \t";
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
    }
}