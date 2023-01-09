#include<iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;

ostringstream str1;
string geek;

string repeat(string s, int n)
{
    string s1 = s;
    for(int i=1; i<n;i++)
    s += s1;
    return s;
}
int super(string n)
{   
    int temp=0;
    while(n>="1"&&n<="9"){
        for(int i=0;i<3;i++){
            return temp+n[i]+super(temp);
        }
    }
}
int main(){
    int res;
    int k;
    string s,s1;
    cin>>s>>k;
    s1=repeat(s,k);
    super(s1);
    cout<<res;
}
