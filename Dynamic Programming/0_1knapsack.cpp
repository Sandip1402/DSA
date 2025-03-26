// given weight and value of items & total weight capacity. Get maximum value within
// given given weight capacity
#include<bits/stdc++.h>
using namespace std;
// using recursion, time complexity - O(2^n)
int knapsack(int wt[], int val[], int cap, int n){
    if(n==0 || cap==0)
        return 0;
    if(wt[n-1]>cap)
        return knapsack(wt,val,cap,n-1);
    else
        return max(knapsack(wt,val,cap,n-1),val[n-1]+knapsack(wt,val,cap-wt[n-1],n-1));
}
// using dynamic programming, time complexity - O(n * W)
int knapsack1(int wt[], int val[], int W, int n) {
    int dp[n+1][W+1];
    for(int i=0; i<=W; i++){dp[0][i]=0;}
    for(int i=0; i<=n; i++){dp[i][0]=0;}
    // row for wt, column for capacity
    for(int i=1; i<=n; i++){
        for(int j=1; j<=W; j++){
            if(wt[i]>W){
                dp[i][j]=dp[i-1][j];
            }
            else{
                int x = j-wt[i-1];
                dp[i][j]=max( dp[i-1][j] , val[i]+dp[i-1][x] );
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int wt[] = {4,5,1,7,3,2};
    int val[] = {1,2,3,4,5,6};
    int cap = 17;
    cout<<knapsack(wt,val,cap,6)<<endl;
    cout<<knapsack1(wt, val, cap, 6);
    return 0;
}