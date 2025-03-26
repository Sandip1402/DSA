#include<iostream>
#include<vector>
using namespace std;
// ways to create multidimensional array in cpp
// row major, where addresses are assigned row wise(Cpp follows row major)
// column major, where addresses are assigned column wise
// variable sized matrix
// using double pointer (not cache friendly, easy function passing)
int** CreateDoublePointer(int m, int n){
    int **arr; // double pointer
    arr = new int *[m]; // creating array of m pointers, pointing them with arr
    // every first element in row is a pointer.
    for(int i=0; i<m; i++){
            arr[i]=new int [n]; // every row is an array of n size
    }
    // to assign values
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=10; // assigning same value
        }
    }
    return arr;
}
// using array of pointers
int* CreatePointerArray(int m, int n){
    int *arr[m]; // taking array of pointers
    for(int i=0; i<m; i++){
        arr[i] = new int [n];
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i][j]=10;
        }
    }
    return arr; // returning array of pointers
}
// array of vectors(not cache friendly, rows are dynamic size, easy function passing)
vector<int>* CreateVectorArray(int m, int n){
    vector<int> *arr = new vector<int>[m];// array of vector
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            arr[i].push_back(10);
        }
    }
    return arr;
}
// vector of vectors(number of rows are also dynamic, easy function passing)
vector<vector<int>> CreateVectorVector(int m, int n){
    vector<vector<int>>arr;
    for(int i=0; i<m; i++){
        vector<int>v;
        for(int j=0; j<n; j++){
            v.push_back(10);
        }
        arr.push_back(v);
    }
    return arr;
}
// printing
void printMatrix(int **arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
void printMatrix(int *arr[], int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
void printMatrix(vector<int>*arr, int m, int n){
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
void printMatrix(vector<vector<int>>&arr, int m, int n){ // using reference to avoid copying
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++)
            cout<<arr[i][j]<<" ";
    }
    cout<<endl;
}
int main(){
    int **a1 = CreateDoublePointer(3,2);
    int **a2 = CreatePointerArray(3,2);
    vector<int>*a3 = CreateVectorArray(3,2);
    vector<vector<int>>a4 = CreateVectorVector(3,2);
    printMatrix(a1,3,2);
    printMatrix(a2,3,2);
    printMatrix(a3,3,2);
    printMatrix(a4,3,2);
    return 0;
}