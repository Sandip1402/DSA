// program to findout longest subsequnce of numbers
#include<bits/stdc++.h>
using namespace std;
int longest_subsequence(int arr[], int n){
    unordered_set<int>s(arr,arr+n);
    int count,res=0;
    for(auto x : s){
        count=0;
        if(s.find(x-1)==s.end()){
            count++;
            int j=x;
            while(s.find(++j)!=s.end()){
                count++;
            }
            res = max(count,res);
        }
    }
    return res;
}
int main()
{
    int n; 
    cout<<"enter size : ";
    cin>>n;
    int arr[n];
    cout<<"enter elements :";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Length of longest subsequence is " << longest_subsequence(arr,n);
    return 0;
}