// program to find no. of least operations required to convert one string into another
// operations are replace, delete, insert
// CAT -> CUT => 1 operation
#include<bits/stdc++.h>
using namespace std;
// recursion method
int eD(string s1, string s2, int m, int n){
    // base cases
    if(m==0) return n;  
    /* as we need to add remaining of s2 into s1 for convertion.
    so, n insertion operation */
    if(n==0) return m;
    /* as we need to delete remaining of s1 string.*/
    if(s1[m-1]==s2[n-1])
        return eD(s1,s2,m-1,n-1);
    else{
        return 1+min(eD(s1,s2,m-1,n), // deletion
                    min(eD(s1,s2,m,n-1), // insertion
                        eD(s1,s2,m-1,n-1))); // replace
        /* adding 1 as any one of the operation is single operation */
    }
}
// tabulation method
// time - theta(m*n)
int eD_tab(string s1,string s2){
    int m,n;
    m=s2.length(); // row for s2
    n=s1.length(); // column for s1
    int ed_matrix[m+1][n+1];
    for(int i=0; i<=n; i++)
        ed_matrix[0][i]=i;
    for(int i=1; i<=m; i++)
        ed_matrix[i][0]=i;
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(s1[j-1]==s2[i-1])
                ed_matrix[i][j]=ed_matrix[i-1][j-1]; // copying diagonal value
            else{
                ed_matrix[i][j]= 1+min(ed_matrix[i-1][j], // inserting
                                    min(ed_matrix[i-1][j-1], // replacing
                                        ed_matrix[i][j-1])); // deleting
            }
        }
    }
    return ed_matrix[m][n];
}
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    cout<<"No. of operation require : "<<eD(s1,s2,s1.length(),s2.length())<<endl;
    cout<<"No. of operation require : "<<eD_tab(s1,s2);
    return 0;
}