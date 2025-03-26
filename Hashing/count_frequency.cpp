#include<bits/stdc++.h>
using namespace std;
// naive method
// time complexity - O(n square), aux space - O(1)
void freq1(int arr[], int n){
    for(int i=0; i<n; i++){
        bool flag = false; // used to check if already counted
        for(int j=0; j<i; j++){
            if(arr[i]==arr[j]){
                flag=true; // already counted
                break;
            }
        }
        if(flag==true)
        continue;
        int freq=1;
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j])
            freq++;
        }
        cout << "freq of "<<arr[i]<<"is "<<freq<<endl;
    }
}
// time complexity - theta(n), aux space - O(n)
void freq2(int arr[], int n){
    unordered_map<int,int> f;
    for(int i=0; i<n; i++){
        f[arr[i]]++;
    }
    // to print in order of appearence
    for(int i=0; i<n; i++){
        if(f[arr[i]]!=-1){
            cout<<"freq of "<<arr[i]<<" is "<<f[arr[i]]<<endl;
            f[arr[i]]=-1;
        }
    }
    // for(auto x : f){
    //     cout<<"freq of "<<x.first<<" is "<<x.second<<endl;
    // }
}
int main()
{
    int arr[]={50,50,10,40,10};
    int n=sizeof(arr)/sizeof(int);
    freq1(arr,n);
    cout<<endl;
    freq2(arr,n);
    return 0;
}