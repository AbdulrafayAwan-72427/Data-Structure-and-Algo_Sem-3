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
    cout<<"Array is: ";
    for(int i = 0; i <size; i++){
        cout<<*(p+i)<<" ";
    }
    int key, low = 0, high = size - 1;
    int mid, pos = -1;
    cout << "Enter number to search: ";
    cin >> key;
    while (low <= high)  {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            pos = mid;
            break;  }
        else if (key > arr[mid]) {
            low = mid + 1; }
        else    {
            high = mid - 1;  }  }
    if (pos != -1)
        cout << "Number found at index " << pos;
    else
        cout << "Number not found.";
    return 0;
}