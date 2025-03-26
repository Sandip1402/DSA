#include<bits/stdc++.h>
using namespace std;
//check only prime numbers
//time complexity square root of x
//worst time taken for prime numbers 
void prime_factors(int x)
{
    //first check no of 2's
    while(x%2==0)
    {
        cout<<2<<endl;
        x/=2;
    }
    //second check no of 3's
    while(x%3==0)
    {
        cout<<3<<endl;
        x/=3;
    }
    for(int i=5; i*i<=x; i+=6)
    {
        while(x%i==0)
        {
            cout<<i<<endl;
            x/=i;
        }
        while(x%(i+2)==0)
        {
            cout<<i+2<<endl;
            x/=(i+2);
        }
    }
    if(x>3)
    cout<<x;
}
int main()
{
    int n;
    cin>>n;
    prime_factors(n);
    return 0;
}