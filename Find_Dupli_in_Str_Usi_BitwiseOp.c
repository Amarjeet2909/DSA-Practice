#include<stdio.h>

int main(){
    char A[]= "finding";
    int i;
    long long int h=0;
    long long int x=0;
    for(i=0;A[i]!='\0';i++)
    {
        x=1;
        x= (x<<(A[i]-97));

        if(x&h>0){
        printf("%c id Duplicate",A[i]);
        }
        else
        h = x | h;
    }
    return 0;
}