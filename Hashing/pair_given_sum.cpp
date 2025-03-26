#include<bits/stdc++.h>
using namespace std;
// naive approach, time - O(n^2), aux space - O(1)
bool pair1(int arr[], int n, int x){
    for(int i=0; i<n; i++){
        int find = x-arr[i];
        for(int j=i+1; j<n; j++){
            if(arr[j]==find)
                return true;
        }
    }
    return false;                                                            
}
// efficient approach, time - O(n), aux space - O(n)
bool pair2(int arr[], int n, int x){
    unordered_set<int>s;
    for(int i=0; i<n; i++){
        if(s.find(x-arr[i])!=s.end())
            return true;
        else
            s.insert(arr[i]);
    }
    return false;
}
int main()
{
    int arr[]={8,3,4,2,5};
    cout<<pair1(arr,5,10)<<endl;
    cout<<pair2(arr,5,10);
    return 0;
}