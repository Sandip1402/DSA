// get the transpose of a matrix
#include<bits/stdc++.h>
using namespace std;
void transpose(int **arr, int m, int n){
    int t,i,j;
    for(i=0; i<m; i++){
        for(j=i+1; j<n; j++){
            t=arr[i][j];  
            arr[i][j]=arr[j][i];
            arr[j][i]=t;
        }
    }
    cout<<endl;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
    cout<<endl;
    }
}
int** CreateDoublePointer(int **arr, int m, int n){
    arr = new int *[m]; // creating array of m pointers, pointing them with arr
    // every first element in row is a pointer.
    for(int i=0; i<m; i++){
            arr[i]=new int [n]; // every row is an array of n size
    }
    // enter values
    cout<<"enter values :"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j]; // assigning same value
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return arr;
}
int main()
{
    int m,n,**arr;
    cout<<"enter dimension of matrix(m * m):"<<endl;
    cin>>m>>n;
    arr=CreateDoublePointer(arr,m,n);
    transpose(arr,m,n);
    delete arr;
    return 0;
}