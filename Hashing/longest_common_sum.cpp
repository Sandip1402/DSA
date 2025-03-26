// program to find longest subarray of sum common in two binary array of same length
#include<bits/stdc++.h>
using namespace std;
// naive approach
int longest_common(int arr1[], int arr2[], int n){
    int pre_sum=0,len=0;
    unordered_map<int,int>s;
    for(int i=0; i<n; i++){
        arr2[i]=arr1[i]-arr2[i];
    }
    for(int i=0; i<n; i++){
        pre_sum+=arr2[i];
        if(pre_sum==0)
        len = i+1;
        if(s.find(pre_sum)==s.end()){
            s[pre_sum]=i;
        } else {
            len=max(len,i-s[pre_sum]);
        }
    }
    return len;
}
int main()
{
    int arr1[] = {0,1,0,0,0,0};
    int arr2[] = {1,0,1,0,0,1};
    cout<<longest_common(arr1,arr2,6);
    return 0;
}