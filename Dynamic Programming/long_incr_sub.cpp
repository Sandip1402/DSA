/* program to find out length of longest increasing subsequence in an 
    integer array. if [2,3,4,7,5,6] then longest increasing subsequence 
    will be [2,3,4,5,6] of length 5*/
#include<bits/stdc++.h>
using namespace std;
// time - theta(n^2)
int lngincrsub(int a[], int n){
    int t[n], max;
    t[0]=1;
    for(int i=1; i<n; i++){
        max=0;
        for(int j=i-1; j>=0; j--){
            if(a[j]<a[i] && max<t[j])
                max=t[j];
        }
        t[i]= 1+max;
    }
    max=0;
    for(int i=0; i<n; i++)
    {
        if(max<t[i])
            max=t[i];
    }
    return max;
}
// using binary search , time-O(nlogn), aux space - O(n)
void top(vector<int> &tail, int a){
    int l=0,h=tail.size()-1,mid;
    while(l<h){
        mid = l+(h-l)/2; // for bigger values
        if(tail[mid]<a)
            l=mid+1;
        else
            h=mid;
    }
    tail[l]=a; 
}
int lngincrsub1(int a[], int n){
    vector<int>tail; // used to store the tail last element of every subsequence in sorted form
    tail.push_back(a[0]);
    for(int i=1; i<n; i++){
        if(tail.back()<a[i])
            tail.push_back(a[i]); // add in tail if new bigger element comes
        else{
            top(tail,a[i]); // find position of smaller element and replace
        }
    }
    return tail.size();
}
int main()
{
    int n;
    cin>>n;
    int ar[n];
    for(int i=0; i<n; i++)
        cin>>ar[i];
    cout<<"length of longest increasing subsequence is : "<<lngincrsub(ar,n)<<endl;
    cout<<"length of longest increasing subsequence is : "<<lngincrsub1(ar,n);
    return 0;
}