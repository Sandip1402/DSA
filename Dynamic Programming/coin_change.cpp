/*  program to find out no. of ways to collect sum(money), given 
    that we can take any coins multiple times.
*/
#include<bits/stdc++.h>
using namespace std;
// naive solution, time complexity - O(2^n)
int coin_change_recur(int coins[], int n, int s){
    if(s==0)
        return 1;
    if(s<0)
        return 0;
    if(n==0)
        return 0;
    return coin_change_recur(coins,n,s-coins[n-1])
            +coin_change_recur(coins,n-1,s);
}
// using tabulation, time complexity - O(n*s), aux space - O(n*s)
int dp[100][100];
int coin_change_tabulation(int coins[], int n, int s){
    dp[n+1][s+1];
    for(int i=0; i<=n; i++)
        dp[i][0]=1;
    for(int i=1; i<=s; i++)
        dp[0][i]=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=s; j++){
            dp[i][j] = dp[i-1][j];
            if(coins[i-1]<=j)
                dp[i][j] += dp[i][j-coins[i-1]];
        }
    }
    return dp[n][s];
}
int main()
{
    int n,s;
    cout<<"enter size of array : ";
    cin>>n;
    int coins[n];
    cout<<"enter elements : "<<endl;
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    cout<<"enter total sum : ";
    cin>>s;
    cout<<"No. of ways to get sum(by recursion) : "<<coin_change_recur(coins,n,s)<<endl;
    cout<<"No. of ways to get sum(by memoization) : "<<coin_change_tabulation(coins,n,s)<<endl;
    return 0;
}