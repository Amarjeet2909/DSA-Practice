#include <iostream>
using namespace std;

int main(){
    int i;
    char s[]="AMARJEET";
    for(i=0;s[i]!='\0';i++)
    {
        s[i]=s[i]+32;
    }
    cout << endl << s;
    return 0;
}