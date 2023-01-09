#include <iostream>
using namespace std;

int main(){
       int word=1;
       char A[]="Amarjeet Is Software    Engineer";
       for(int i=0;A[i]!='\0';i++)
       {
           if(A[i]==' ' && A[i-1]!=' ')
           {
                word++;
           }
       }
       cout << endl << word;
       return 0;
}