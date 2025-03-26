// The program is to count distinct element in every window of a size k
#include<bits/stdc++.h>
using namespace std;
// naive solution,
void distinct_element_window(int arr[], int n, int k){}
// efficient solution, time - theta(n), aux space - O(k)
void distinct_element_window1(int arr[], int n, int k){
    unordered_map<int,int>s;
    for(int i=0; i<k; i++){
        s[arr[i]]++;
    }
    cout<<s.size()<<" ";
    for(int i=k; i<n; i++){
        if(s[arr[i-k]]>1)
            s[arr[i-k]]--;
        else
            s.erase(arr[i-k]);
        if(s.find(arr[i])==s.end())
            s[arr[i]]++;
        cout<<s.size()<<" ";
    }
}
int main()
{
    int n,k; 
    cout<<"enter size : ";
    cin>>n;
    cout<<"enter window size :";
    cin>>k;
    int arr[n];
    cout<<"enter elements :";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"list of distinct elements in every window is : " <<endl;
    distinct_element_window1(arr,n,k);
    return 0;
}