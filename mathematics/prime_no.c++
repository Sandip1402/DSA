#include<iostream>
using namespace std;
// time complexity ✓n (worst case for prime number)
// only required to check until ✓n
// this program only checks with prime numbers
bool prime(int n)
{
    if(n==1)
    return false;
    if(n==2||n==3)
    return true;
    if(n%2==0||n%3==0)
    return false;
    for(int i=5; i*i<=n; i+=6)
    {
        if(n%i==0||n%(i+2)==0)
        return false;
    }
    return true;
}
// function to count the zeros at the end of factorial of a number n
// we need to count the number of 5's,25's,125's in a number, factorial not needed
int trailing_zeros(int n)
{
    int count=0;
    for(int i=5; i<n; i=i*5)
    count+=n/i;
    return count;
}
int main()
{
    int n;
    cin>>n;
    if(prime(n))
    cout<<"prime number"<<endl;
    else
    cout<<"not a prime"<<endl;
    // cout<<trailing_zeros(n);
    return 0;
}