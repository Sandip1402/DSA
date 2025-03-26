#include<bits/stdc++.h>
using namespace std;
/* to find out whether there exist a subarray
    with given sum or not. */
// efficient approach, time complexity - O(n), aux spac - O(n)
bool subarrayWithGivenSum(int arr[], int n, int sum){
    int pre_sum=0;
    unordered_set<int> s;
    for(int i=0; i<n; i++){
        pre_sum+=arr[i];
        // if(pre_sum==sum)
        //     return true;
        if(s.find(pre_sum-sum)!=s.end()){
            return true;
        }else{
            s.insert(pre_sum);
        }
    }
    return false;
}
int main()
{
    int arr[] = {5,8,6,13,3,-1};
    cout<<subarrayWithGivenSum(arr,6,29);
    return 0;
}