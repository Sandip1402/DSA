#include<bits/stdc++.h>
using namespace std;
// naive solution -- O(n)
bool ispoweroftwo_1(int n)
{
    if(n==0)
        return false;
    while(n!=1)
    {
        if(n%2!=0)
        {
            return false;
        }
        n=n/2;
    }
    return true;
}
// brian kernighan -- O(1)
bool ispoweroftwo_2(int n)
{
    if(n==0)
    return false;
    // else if((n&(n-1))==0)
    // return true;
    // else
    // return false;-
    // can be written as
    return ((n&&(n&(n-1)))==0);
}
int main()
{
    int n;
    cout<<"enter a number :"<<endl;
    cin>>n;
    if(ispoweroftwo_1(n))
    cout<<"it is a power of two."<<endl;
    else
    cout<<"not a power of 2."<<endl;
    if(ispoweroftwo_2(n))
    cout<<"it is a power of two."<<endl;
    else
    cout<<"not a power of 2."<<endl;
}