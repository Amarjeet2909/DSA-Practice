#include <iostream>
using namespace std;

int main(){
    char *s="Amarjeet";
    int i;
    int temp=0;
    for(i=0;s[i]!='\0';i++)
    {
         temp++;
    }
    cout << "*************" << temp;
    return 0;
}