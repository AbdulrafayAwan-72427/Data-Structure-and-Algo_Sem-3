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
    cout<<"Before Sorting array is: ";
    for(int i = 0; i <size; i++){
        cout<<*(p+i)<<" ";
    }
    int minIndex,temp;
    for(int i=0;i<size-1;i++){
        minIndex = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[minIndex]){
               minIndex = j; 
            }
        }
        temp = arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=temp;
    }
    cout<<"order: ";
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
} 