// common elements of two unsorted array. Both the array has distinct elements
#include<bits/stdc++.h>
#include<chrono> // to calculate execution time
using namespace std;
// naive method
// time complexity - O(m*n), aux space - O(1)
void intersection1(int arr1[], int arr2[], int m, int n){
    for(int i=0; i<m; i++){
        int flag=false; // to check common or not
        for(int j=0; j<m; j++){
            if(arr2[j]==arr1[i]){
                cout<<arr1[i]<<" ";
                break;
            }
        }
    }
}
// effecient method
// time complexity - O(m+n), aux space - O(n)
void intersection2(int arr1[], int arr2[], int m, int n){
    unordered_set<int> s(arr2,arr2+n); // inserting elements of arr2 or,
    // for(int i=0; i<n; i++){ // to print as appearence in arr1 we are inserting arr2
    //     s.insert(arr2[i]);
    // }
    for(int i=0; i<m; i++){
        if(s.find(arr1[i])!=s.end()){
            cout<<arr1[i]<<" ";
            continue;
        }
    }
}
int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    int arr1[] = {10,20,30};
    int arr2[] = {30, 10};
    intersection1(arr1,arr2,3,2);
    cout<<endl;
    intersection2(arr1,arr2,3,2);
    auto end = std::chrono::high_resolution_clock::now();
    // auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();
    // float exe = (float)duration / 1000000000;
    std::chrono::duration<double>exe = end - start;
    cout<<endl<<"Execution Time :"<<exe.count()<<"s"<<endl;
    return 0;
}
