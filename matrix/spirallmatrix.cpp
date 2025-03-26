// problem is to print a matrix in spiral form
// 1  2  3   4 
// 5  6  7   8       => 1 2 3 4 8 12 11 10 9 5 6 7
// 9  10 11  12
#include<bits/stdc++.h>
using namespace std;
// time complexity - theta (m * n)
void spiralmatrix(vector<vector<int>>&matrix, int m, int n){
    // top & bottom is for row, left & right is for column
    int left, right, top, bottom;
    top=left=0, right=n-1, bottom=m-1;
    while(top<=bottom && left<=right){
        for(int i=left; i<=right; i++)
            cout<<matrix[top][i]<<" ";
        top++;
        for(int i=top; i<=bottom; i++)
            cout<<matrix[i][right]<<" ";
        right--;
        if(top<=bottom){
            for(int i=right; i>=left; i--)
                cout<<matrix[bottom][i]<<" ";
            bottom--;
        }
        if(left<=right){
            for(int i=bottom; i>=top; i--)
                cout<<matrix[i][left]<<" ";
            left++;        
        }
    }
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
    cout<<"enter values :"<<endl;
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
    vector<vector<int>>arr;
    int m,n;
    cout<<"enter dimension :";
    cin>>m>>n;
    CreateMatrix(arr,m,n);
    printMatrix(arr,m,n);
    spiralmatrix(arr,m,n);
    return 0;
}