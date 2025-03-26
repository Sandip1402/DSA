// programm to find out if there is a subarray with sum 0
#include<bits/stdc++.h>
using namespace std;
// naive approache, time - O(n^2), space - O(1)
bool subarray_sum1(int arr[], int n){
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=arr[j];
            if(sum == 0)
                return true;
        }
    }
    return false;
}
// efficient approach, time - O(n), space - O(n)
bool subarray_sum2(int arr[], int n){
    unordered_set<int>s;
    int pre_sum=0;
    for(int i=0; i<n; i++){
        pre_sum+=arr[i];
        if(s.find(pre_sum)!=s.end()){
            return true;
        }
        if(pre_sum==0)
            return true;
        s.insert(pre_sum);
    }
    return false;
}
int main()
{
    int arr[] = {-3,4,-3,1,-1};
    cout<<subarray_sum1(arr,5)<<endl;
    cout<<subarray_sum2(arr,5);
    return 0;
}