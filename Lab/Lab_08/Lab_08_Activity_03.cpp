#include<iostream>
using namespace std;
int main(){

    int (*arr)[2] = new int[2][2];

    cout<<"Enter 4 Elements: "<<endl;
    for(int i = 0; i <2; i++){
        for(int j = 0; j <2; j++){
            cin>>arr[i][j];
        }
    }
    cout<<"User Entered: "<<endl;
    for(int i = 0;i<2;i++){
        for(int j = 0; j <2; j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}
