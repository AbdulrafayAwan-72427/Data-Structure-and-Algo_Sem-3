#include <iostream>
using namespace std;
int main(){
    int const size = 25;
    int arr1[size];
    int arr2[size];
    int deafult[size];
    for (int i = 0; i<size;i++){
        arr1[i]= i + 1;
    }
    for (int i =0; i<size;i++){
        arr2[i]= (i+1) *10;
    }
   cout<<"Befor Swapping: "<<endl;
   cout<<"Array 1 values are: ";
      for (int i = 0; i<size;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Array 2 values are: ";
    for (int i =0; i<size;i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;
    for (int i=0;i<size;i++){
        deafult[i]=arr1[i];
        arr1[i]=arr2[i];
        arr2[i]=deafult[i];

    }
     cout<<"After Swapping: "<<endl;
   cout<<"Array 1 values are: ";
      for (int i = 0; i<size;i++){
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    cout<<"Array 2 values are: ";
    for (int i =0; i<size;i++){
        cout<<arr2[i]<<" ";
    }
}

