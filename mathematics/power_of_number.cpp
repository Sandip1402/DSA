#include<bits/stdc++.h>
using namespace std;
int recursive_power(int a, unsigned int b)
{
    if(b==0)
    return 1;
    long long int c=recursive_power(a,b/2);
    c=c*c;
    if(b%2==0)
    return c;
    else
    return a*c;
}
//the logic is any power can be writter in terms of binary bits
//4^7 can be writte 4^4 * 4^2 * 4^1 * 4^0 (1110, as it is multiplication)
int iterative_power(int a, unsigned int b)
{
    long long ans=1;
    while(b>0)
    {
        if(b%2!=0)
        ans=ans*a;
        a=a*a;
        b=b/2;
    }
    return ans;
}
int main()
{
    int a;
    unsigned int b;
    cin>>a>>b;
    cout<<recursive_power(a,b)<<endl;
    cout<<iterative_power(a,b)<<endl;
    return 0;
}