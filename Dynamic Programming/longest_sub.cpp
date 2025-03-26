// program to find out longest common subsequence b/w to string using dynamic programming
#include<bits/stdc++.h>
using namespace std;
// using simple recursion
// time complexity - O(2^n)
int lcs_recur(string s1, string s2, int m, int n){
    if(m==0 || n==0)
        return 0;
    if(s1[m-1]==s2[n-1])
        return 1+lcs_recur(s1,s2,m-1,n-1);
    else
        return max(lcs_recur(s1,s2,m-1,n),lcs_recur(s1,s2,m,n-1));
}
// using memoization
// time complexity - theta(mn), aux space - O(mn)
int memo[100][100];
int lcs_memo(string s1, string s2, int m, int n){
    if(memo[m][n]!=-1)
        return memo[m][n];
    if(m==0 || n==0)
        memo[m][n] = 0;
    else{
        if(s1[m-1]==s2[n-1]){
            memo[m][n]=1+lcs_memo(s1,s2,m-1,n-1);
        } else{
            memo[m][n] = max(lcs_memo(s1,s2,m-1,n),lcs_memo(s1,s2,m,n-1));
        }
    }
    return memo[m][n];
}
// using tabulation
// time complexity - theta(m*n), aux space - theta(m*n);
int lcs_tabu(string s1, string s2, int m, int n){
    int tabu[m+1][n+1],i,j;
    for(int i=0; i<=n; i++)
        tabu[0][i]=0;
    for(int i=0; i<=m; i++)
        tabu[i][0]=0;
    for(i=1; i<=m; i++){
        for(j=1; j<=n; j++){
            if(s1[i-1]==s2[j-1]){
                tabu[i][j]=1+tabu[i-1][j-1];
            }else{
                tabu[i][j]=max(tabu[i-1][j],tabu[j][j-1]);
            }
        }
    }
    return tabu[m][n];
}
int main(){
    string s1,s2;
    int m,n;
    cout<<"enter size of string1 : ";
    cin>>m;
    cout<<"enter string : ";
    cin>>s1;
    cout<<"enter size of string2 : ";
    cin>>n;
    cout<<"enter string : ";
    cin>>s2;
    memo[m+1][n+1];
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            memo[i][j]=-1;
        }
    }
    cout<<"Strings are : "<<s1<<" "<<s2<<endl;
    cout<<"longest common subsequence via recursion : "<<lcs_recur(s1,s2,m,n)<<endl;
    cout<<"longest common subsequence via memoization : "<<lcs_memo(s1,s2,m,n)<<endl;
    cout<<"longest common subsequence via tabulation : "<<lcs_tabu(s1,s2,m,n);
    return 0;
}