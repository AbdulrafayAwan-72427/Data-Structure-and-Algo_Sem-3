#include <iostream>
using namespace std;
int main(){
    const int  size = 7;
    int marks[size];
    int *p = marks;
    cout<<"Enter 7 numbers: "<<endl;
    for(int i=0;i<7;i++){
       cin>>*(p+i);
    }
    int max = *p;
    int min = *p;

        for(int i=0;i<7;i++){
        if(*(p+i)>max){
            max = *(p+i);
        }
    }
    cout<<"Maximum Value is: "<<max<<endl;
    for(int i=0;i<7;i++){
        if(*(p+i)<min){
            min = *(p+i);
        }
    }
    cout<<"Minimum Value is: "<<min<<endl;


}