    #include <iostream>
using namespace std;
int main()
{
    int size;
    cout<<"Enter Size of array: ";
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
    cout<<endl;
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <(size-1) - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout<<"After Sorting array is: ";
    for(int i = 0; i <size; i++){
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
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