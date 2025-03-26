// problem is to search an element in a row-wise and column-wise sorted matrix
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
void search(vector<vector<int>>matrix, int m, int n){
    int x;
    cout<<"enter value to find :"<<endl;
    cin>>x;
    int i=0, j=n-1;
    while(i<m && j>=0){
        if(matrix[i][j]==x)
            cout<<"found at ("<<i<<","<<j<<")"<<endl;
        else if(matrix[i][j]>x)
            j--;
        else
            i++;
    }
    cout<<"element not found"<<endl;
}
void printMatrix(vector<vector<int>>arr, int m, int n){
    cout<<"The matrix is :"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void CreateMatrix(vector<vector<int>>&arr, int m, int n){
    int x;
    cout<<"enter matrix values :"<<endl;
    for(int i=0; i<m; i++){
        vector<int>v;
        for(int j=0; j<n; j++){
            cin>>x;
            v.push_back(x);
        }
        arr.push_back(v);
    }
}
int main()
{
    vector<vector<int>>matrix;
    int m, n;
    cout<<"enter dimension :"<<endl;
    cin>>m>>n;
    fflush(stdin);
    CreateMatrix(matrix,m,n);
    printMatrix(matrix,m,n);    
    search(matrix,m,n);
    return 0;
}