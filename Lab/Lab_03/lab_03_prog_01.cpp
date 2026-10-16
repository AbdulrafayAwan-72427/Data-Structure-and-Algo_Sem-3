#include<iostream>
using namespace std;
class Task{
    private:
        int size;
        int *arr;
    public:
    Task(){

        size = 0;
        arr =new int[size];
    }
    void user_input(){
        cout<<"Enter Size of Array"<<" ";
        cin>>size;
        cout<<"Enter Elenments of Array"<<endl;
        for(int i = 0;i<size;i++){
            cin>>arr[i];
        }
    }
    int get_length(){
        return size;
    }
    void delete_element(){
        int position;
        cout<<"Enter Index to delete and Element: "<<" ";
        cin>>position;
        if (position>=1&&position<=size){
            for (int i = position;i<size-1;i++){
                arr[i]=arr[i+1];
            }
            size--;
        }
    }
    void display(){
                for(int i = 0;i<size;i++){
            cout<<arr[i]<<" ";
        
        }
    }   
};
int main(){
    Task stupid;
    stupid.user_input();
    stupid.display();
    stupid.delete_element();
    cout<<"After deletion: "<<endl;
    stupid.display();
    cout<<"Length: "<<stupid.get_length()<<endl;
}