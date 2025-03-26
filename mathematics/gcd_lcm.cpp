#include<iostream>
using namespace std;
//O(min(a,b))
int gcd(int a, int b)
{
    int c=min(a,b);
    for(int i=2; i<=c; i++)
    {
        if(a%i==0&&b%i==0)
        return i;
    }
    return 1;
}
//O(min(a,b))
int euclidean_gcd(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
        a=a-b;
        else
        b=b-a;
    }
    return a;
}
//O(log(min(a,b)))
int optimised_gcd(int a, int b)
{
    if(b==0)
    return a;
    else
    optimised_gcd(b,a%b);
    //one line answer
    //return b==0?a:optimised_gcd(b,a%b)
}
int lcm(int a,int b)
{
    int c=optimised_gcd(a,b);
    return (a*b)/c;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<"LCM is : "<<lcm(a,b)<<endl;
    cout<<"GCD using different method :"<<endl;
    cout<<"normal method : "<<gcd(a,b)<<endl;
    cout<<"euclidean method : "<<euclidean_gcd(a,b)<<endl;
    cout<<"optimised gcd : "<<optimised_gcd(a,b);
    return 0;
}