// distinct elements in an array
#include<bits/stdc++.h>
using namespace std;
// naive solution 
int distinct1(int arr[], int n){
    int res=0;
    bool dist;
    for(int i=0; i<n; i++){
        dist=true;
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                dist=false;
                break;
            }
        }
        if(dist==true)
            res++;
    }
    return res;
}
//using unordered set
int distinct2(int arr[], int n){
    unordered_set<int> a;
    for(int i=0; i<n; i++){
        a.insert(arr[i]);
    }
    return a.size();
}
// shorter method using unordeted_set
int distinct3(int arr[], int n){
    // we can pass reference also to insert
    unordered_set<int> a(arr,arr+n); // accomodates with only distinct elements in array
    return a.size();
}
int main()
{
    int arr[] = {1,3,1,6,5,6,4,5};
    int n = sizeof(arr)/sizeof(int);
    cout<<distinct1(arr,n)<<endl;
    cout<<distinct2(arr,n)<<endl;
    cout<<distinct3(arr,n)<<endl;
    return 0;
}