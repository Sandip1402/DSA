// basics of dynamic programming, memoization & tabulation method
#include<bits/stdc++.h>
using namespace std;
int memo[1000];
// time complexity - theta(n), aux space theta(n);
int memoization_fib(int n){
    if(memo[n]==-1){
        int res;
        if(n==1 || n==0)
            memo[n] = n;
        else
            memo[n] = (memoization_fib(n-1) + memoization_fib(n-2))%1000000007;
    }
    return memo[n];
}
// time complexity - theta(n), aux space - theta(n)
int tabulation_fib(int n){
    int tbln[n+1];
    tbln[0]=0; tbln[1]=1;
    for(int i=2; i<=n; i++){
        tbln[i] = (tbln[i-1] + tbln[i-2])%1000000007;
    }
    return tbln[n];
}
int main()
{
    int n;
    cout<<"enter fibonacci position : ";
    cin>>n;
    memo[n+1];
    for(int i=0; i<=n; i++)
        memo[i]=-1;
    cout<<"Nth fibonacci number using memoization : "<< memoization_fib(n) <<endl;
    cout<<"Nth fibonacci number using tabulation : "<< tabulation_fib(n) <<endl;
    return 0;
}