#include <iostream>
using namespace std;
int main(){
    int i,j,k;
    int temp;
    char s[]= "HGNIS TEEJRAMA";
    for(i=0;s[i]!='\0';i++)
    {

    }
    i=i-1;
    for(k=0;k<i;k++,i--)
    {
        temp=s[k];
        s[k]=s[i];
        s[i]=temp;
    }
    cout << endl << s;
    return 0;
}