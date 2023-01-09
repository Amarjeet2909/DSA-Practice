#include <iostream>
using namespace std;
int main(){
    int i,j;
    char s[] = "teejrama";
    char Corrected[9]={0};
    for(i=7,j=0;i>=0;i--,j++)
    {
        Corrected[j]= s[i];
    }
    cout << endl << Corrected;
    return 0;
}
