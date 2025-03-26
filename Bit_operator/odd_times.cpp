#include<bits/stdc++.h>
using namespace std;
int oddOccuringNumber(int arr[], int n)
{
    int ans=arr[0];
    for(int i=1; i<n; i++)
        ans=ans^arr[i];
    return ans;
}
int main()
{
    int n;
    cout<<"enter no. of elements in array :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter elements of array :"<<endl;
    for(int i=0; i<n; i++)
    cin>>arr[i];
    cout<<"Number occuring odd times :"<<oddOccuringNumber(arr,n);
    return 0;
}