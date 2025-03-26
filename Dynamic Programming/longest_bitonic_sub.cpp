/* program to find out longest bitonic subsequence in an array.
    bitonic subsequnce is an order consisting a bitonic point.
    Before bitonic point elements are in increasing oreder & 
    after bitonic point elements are in decreasing order. */
#include<bits/stdc++.h>
using namespace std;
/* to solve this we combine lis solution and we find 
    another lis from the right side of the array which 
    gives us longest decreasing order from the left side.
    Every element is considered bitonic point and their increasing 
    sequence is stored in lis & decreasing sequence value in lds. */ 
// time complexity - theta(n^2)
int LongestBitonicSub(int arr[], int n){
    int *lis = new int[n];
    int *lds = new int[n];
    int res=0;
    lis[0]=1;
    lds[n-1]=1;
    for(int i=1; i<n; i++){
        lis[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                lis[i]=max(lis[i],1+lis[j]);
            }
        }
    }
    for(int i=n-2; i>=0; i--){
        lds[i]=1;
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[i]){
                lds[i] = max(lds[i],1+lds[j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        int a=lis[i]+lds[i]-1;
        res = max(res, a);
    }
    delete []lis;
    delete []lds;
    return res;
}
void pos(vector<int> &temp, int a, int l, int h){
    int mid;
    while(l<h){
        mid = l + (h-l)/2;
        if(temp[mid]<a)
            l=mid+1;
        else
            h=mid;
    }
    temp[l]=a;
}
int LongestBitonicSubBinary(int arr[], int n){
    vector<int>lis;
    vector<int>lds;
    lis.push_back(arr[0]);
    lds.push_back(arr[n-1]);
    for(int i=0; i<n; i++){
        if(lis.back()<arr[i])
            lis.push_back(arr[i]);
        else
            pos(lis,arr[i],0,lis.size()-1);
    }
    for(int i=0; i<n; i++)
        cout<<lis[i]<<" ";
    cout<<endl;
    for(int i=n-2; arr[i]!=lis.back(); i--){
        if(lds.back()<arr[i])
            lds.push_back(arr[i]);
        else
            pos(lds,arr[i],0,lds.size()-1);
    }
    for(int i=0; i<n; i++)
        cout<<lds[i]<<" ";
    return lis.size()+lds.size()+1;
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];
    cout<<endl<<"Length of longest bitonic subsequence is : "<<LongestBitonicSub(ar,n)<<endl;
    cout<<endl<<"Length of longest bitonic subsequence is : "<<LongestBitonicSubBinary(ar,n);
    return 0;
}