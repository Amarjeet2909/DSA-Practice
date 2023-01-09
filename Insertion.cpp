#include <iostream>
using namespace std;

int main()
{
    int n,length,index,i,element;
    int *arr;
    cout << "Enter the size of the Array:" << endl;
    cin >> n;
    cout << "Enter the length of the Array:" <<endl;
    cin >> length;
    arr = new int(n);
    cout << "Enter the Index for Inserting the element:" << endl;
    cin >> index;
    cout << "Enter the element to insert:" << endl;
    cin >> element;
    cout << "Enter the elements in the Array:" <<endl;
    for(i=0;i<length;i++)
    {
        cin >> arr[i];
    }
    cout << "Elements in the Array before Insertion is:" << endl;
    for(i=0;i<length;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    if(index<=n && index>=0)
    {
        for(i=length;i>index;i--)
        {
            arr[i]=arr[i-1];
        }
        arr[index]=element;
        length++;
    }
    cout << "Array After Insertion is:" << endl;
    for(i=0;i<length;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}