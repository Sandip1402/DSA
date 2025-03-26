#include<bits/stdc++.h>
using namespace std;
int longest_subarray1(int arr[], int n, int sum){
    unordered_map<int,int>s;
    int pre_sum=0, max_length=0;
    for(int i=0; i<n; i++){
        pre_sum+=arr[i];
        if(pre_sum == sum)
            max_length=i+1;
        if(s.find(pre_sum)==s.end())
            s.insert({pre_sum,i});
        if(s.find(pre_sum-sum)!=s.end()){
            if((i-s[pre_sum]) > max_length)
                max_length=(i-s[pre_sum]);
        }
    }
    for(auto x : s){
        cout<<x.first <<" "<<x.second<<endl;
    }
    return max_length;
}
int main()
{
    int arr[] = {8,3,1,5,-6,6,2,2};
    cout<<longest_subarray1(arr,8,17);
    return 0;
}