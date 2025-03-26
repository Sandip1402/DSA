// code to findout longest subarray with equal 0's and 1's
#include<bits/stdc++.h>
using namespace std;
// efficient solution, time - theta(n), aux space - theta(n)
// approach is to replace 0's with -1's and find sum as 0.
int longest_0_1(int arr[], int n){ 
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            arr[i]=-1;
    }
    int len=0,pre_sum=0;
    unordered_map<int, int>s;
    for(int i=0; i<n; i++){
        pre_sum+=arr[i];
        if(pre_sum==0)
            len = i+1;
        if(s.find(pre_sum)==s.end()){
            s[pre_sum]=i;
        }
        else{
            len = max(len, i-s[pre_sum]);
        }
    }
    for(auto x:s)
    cout<<x.first<<" "<<x.second<<endl;
    return len;
}
int main()
{
    int arr[] = {1,0,0,1,0,1,1};
    cout<<longest_0_1(arr,7);
    return 0;
}