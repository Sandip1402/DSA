/* program to find out maximum sum increasing subsequence in an integer array. */
// [3,20,4,6,7,30], for this array ans will be 53
#include<bits/stdc++.h>
using namespace std;
// time complexity - theta(n^2)
int MaxSumIncrSSqnc(int arr[], int n){
    int *mlis = new int[n];
    int m,mi; // m to store max, mi for index
    mlis[0] = arr[0];
    // for(int i=1; i<n; i++){
    //     for(int j=0; j<i; j++){
    //         if(arr[j]<arr[i] && m<arr[j]){
    //             m=arr[j];
    //             mi=j;
    //         }
    //     }
    //     mlis[i]=mlis[mi]+arr[i];
    // }
    // m=0;
    // for(int i=0; i<n; i++){
    //     m=max(m,mlis[i]);
    // }

// gfg
    for(int i=1; i<n; i++){
        mlis[i] = arr[i]; // if it doesn't make any sub sequence
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i])
            mlis[i] = max(mlis[i], arr[i]+mlis[j]); // compares with updated mlis[i]
        }
    }
    m=0;
    for(int i=0; i<n; i++){
        m=max(m,mlis[i]);
    }
    delete []mlis;
    
    return m;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];
    cout<<"Length of max sum increasing subsequence : "<<MaxSumIncrSSqnc(ar,n)<<endl;
    return 0;
}