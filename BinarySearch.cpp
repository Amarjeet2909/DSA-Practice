#include <iostream>
using namespace std;

struct Array
{
 int A[10];
 int size;
 int length;
};

int BinarySearch(struct Array arr,int key)
{
  int start,end,mid;
  start=0;
  end= arr.length-1;
  while(start<=end)
  {
    mid= (start+end)/2;
    if(key==arr.A[mid])
    {
      return mid;
    }
    else if(key<arr.A[mid])
    {
      end=mid-1;
    }
    else
     start=mid+1;
  }
  return -1;
}

int main(){
  int result;
  struct Array arr1= {{2,4,6,8,12,34,67,89,100},10,9};
  result= BinarySearch(arr1,67);
  cout << "Index of key element by binary search is::" <<" " << result;
  return 0;
}