// union of two unsorted array, counting distinct elements in two unsorted array
// & getting distinct elements
// naive solution
#include<bits/stdc++.h>
using namespace std;
int union1(int arr1[], int arr2[], int m, int n){
    int res=0;
    int j=0;
    int dist[m+n];
    for(int i=0; i<m; i++){
        for(int k=0; k<j; k++){
            if(dist[k]!=arr1[i]){
                res++;
                dist[j++]=arr1[i];
                break;
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int k=0; k<j; k++){
            if(dist[k]!=arr2[i]){
                res++;
                dist[j++]=arr2[i];
                break;
            }
        }
    }
    return res;
}
// time complexity - O(m*m + n*(m+n)), aux space - O(m+n);
// Efficient solution 
int union2(int arr1[], int arr2[], int m, int n){
    unordered_set<int> s(arr1, arr1+m); // constructor syntax to accomodate values
    for(int i=0; i<m; i++){
        s.insert(arr2[i]);
    }
    return s.size();
}
// time complexity - theta(m+n), aux space - O(m+n)
int main()
{
    int a[]={10,30,10};
    int b[]={5,10,5};
    cout<<union1(a,b,3,2);
    cout<<union2(a,b,3,2);
    return 0;
}