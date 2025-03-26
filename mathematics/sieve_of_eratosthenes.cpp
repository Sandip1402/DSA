#include<bits/stdc++.h>
using namespace std;
//function to print all prime numbers till n
//time complexity O(n*loglog n)
void allprimes(int n)
{
    vector<bool>isprime(n+1,true);
    for(int i=2; i<n+1; i++)
    {
        if(isprime[i])
        {
            cout<<i<<endl;
            for(int j=2*i; j<n+1; j=j+i)
            isprime[j]=false;
        }
    }
}
int main()
{
    allprimes(45);
    return 0;
}