#include <iostream>
using namespace std;

void swap(int *p,int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}

int main(){
    int i,j;
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int B[10]={0};
    //Reversing array A by creating a duplicate Array B 
    for(i=9,j=0;i>=0;i--,j++)
    {
        B[j]=A[i];
    }
    //Reversing array by swaping the elements
    for(i=0,j=9;i<j;i++,j--)
    {
        swap(&A[i],&A[j]);
    }
    //displaying Array B
    cout << "Reversed Array is by creating duplicate Array is::" <<endl;
    for(i=0;i<10;i++)
    {
        cout << B[i] << " ";
    }
    cout << endl;
    cout << "Reversed Array is by swaping the elements is::" <<endl;
    for(i=0;i<10;i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
