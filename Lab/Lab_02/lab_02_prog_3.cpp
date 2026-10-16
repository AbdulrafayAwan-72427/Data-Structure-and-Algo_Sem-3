#include <iostream>
using namespace std;
int main(){
    const int  size = 7;
    int data[size];
    int *p = data;
    cout<<"Enter 7 numbers: "<<endl;
    for(int i=0;i<7;i++){
       cin>>*(p+i);
    }
    int search;
    cout<<"Enter Number to search: "<<endl;
    cin>>search;
    bool found = false;
    int index=0;
    for(int i = 0;i<size;i++){
        if (*(p+i) == search){
            found=true;
            index = i+1;         
        }
    }
     if (found) {
        cout<<"Your entered value is at index: "<<index<<endl;
    } else {
        cout<<"Entered number is not present."<<endl;
    }      
}