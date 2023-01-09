#include<stdio.h>

void permu(char str[],int k)
{
    static int A[10]={0};
    static char Res[10];
    int i;
    if(str[k]=='\0')
    {
        Res[k]='\0';
        puts(Res);
    }
    else
    {
        for(i=0;str[i]!='\0';i++)
        {
            if(A[i]==0)
            {
                Res[k]=str[i];\
                   A[i]=1;
                permu(str,k+1);
                A[i]=0;
            }
        }
    }
}

main()
{
    char str[4]="ABC";
    permu(str,0);
}