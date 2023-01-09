#include <iostream>
using namespace std;

void deletion(int arr[],int index)
{
    if(index<=8 && index>=0)
    {
        for(int i=index;i<8;i++)
        {
            arr[i]=arr[i+1];
        }
    }
    cout << "Array after deletion is:" << endl;
    for(int i=0;i<7;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int i,index;
    int arr[8]= {8,5,7,9,6,3,2,1};
    cout << "Enter the index to delete the element:" << endl;
    cin >> index;
    deletion(arr,index);
    return 0;
}