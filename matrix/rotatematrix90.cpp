// program to rotate a matrix by 90 degree
#include<bits/stdc++.h>
using namespace std;
// naive method by using auxiliary space
void rotate1(int **arr, int m, int n){
    // creating array
    int** temp = new int *[m];
    for(int i=0; i<m; i++){
        temp[i] = new int [n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            temp[n-j-1][i]=arr[i][j];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            arr[i][j]=temp[i][j];
    }
    delete temp;
}
// efficient method by not using auxiliary space
// first we transpose then exchange rows
void rotate2(int **arr, int m, int n){
    int t;
    // transpose
    for(int i=0; i<m; i++){
        for(int j=i+1; j<n; j++){
            t=arr[i][j];
            arr[i][j]=arr[j][i];
            arr[j][i]=t;
        }
    }
    //exchange
    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            t=arr[j][i];
            arr[j][i]=arr[m-j-1][i];
            arr[m-j-1][i]=t;
        }
    }
}
int** CreateDoublePointer(int **arr, int m, int n){
    arr = new int *[m];
    for(int i=0; i<m; i++){
            arr[i]=new int [n];
    }
    cout<<"enter values :"<<endl;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    return arr;
}
void printMatrix(int **arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int **arr;
    int m,n;
    cout<<"enter dimension :";
    cin>>m>>n;
    arr = CreateDoublePointer(arr,m,n);
    printMatrix(arr,m,n);
    // rotate1(arr,m,n);
    rotate2(arr,m,n);
    printMatrix(arr,m,n);
    return 0;
}