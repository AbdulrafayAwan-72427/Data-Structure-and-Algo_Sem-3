#include <iostream>
using namespace std;

int main()
{
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
    int temp;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Order: ";

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}