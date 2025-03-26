#include<iostream>
using namespace std;
//function to print all divisors of n
//time complexity O(square root n)
void alldivisors(int n)
{
    int i;
    for(i=1; i*i<n; i++)
    {
        if(n%i==0)
        cout<<i<<endl;
    }
    while(i>=1)
    {
        if(n%i==0)
        cout<<endl<<n/i;
        i--;
    }
}
int main()
{
    int n;
    cin>>n;
    alldivisors(n);
    return 0;
}