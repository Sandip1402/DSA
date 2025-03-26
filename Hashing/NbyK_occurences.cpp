// program to find out elements frequence greater than n/k
#include<bits/stdc++.h>
using namespace std;
// naive solution
void sort_array(int arr[], int n){

}
void NbyK_occurences(int arr[], int n, int k){
    int count = 1;
    int i=1;
    sort_array(arr,n);
    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
            count++;
            i++;
        }
        if(count > (n/k))
            cout<<arr[i]<<" ";
        count=1;
        i++;
    }
}
// efficient solution , time - theta(n), aux space - O(n)
void NbyK_occurences1(int arr[], int n, int k){
    unordered_map<int, int> s;
    for(int i=0; i<n; i++){
        s[arr[i]]++;
    }
    for(auto x : s){
        if(x.second>(n/k))
            cout<<x.first<<" ";
    }
}
// when k is very smaller than n. Maximum k-1 elements can have occurences greater than n/k
void NbyK_occurences2(int arr[], int n, int k){
    unordered_map<int,int> s;
    int count = 0;
    for(int i=0; i<n; i++){
        // add only if the size is less then k(max k-1 element)
        if(s.find(arr[i])==s.end()){
            cout<<"ok"<<" ";
            if(s.size()<k){
                s[arr[i]]++;
            } else{
                for(auto x : s){
                    x.second--;
                    if(x.second==0)
                        s.erase(x.first);
                }
            }
        } else{
            s[arr[i]]++;
        }
    }
    for(auto x : s){
        for(int i=0; i<n; i++){
            if(arr[i]==x.first)
                count++;
        }
        if(count<(n/k))
            s.erase(x.first);
    }
    for(auto x : s)
        cout<<x.first<<" ";
}
int main()
{
    int n,k;
    cout<<"enter size : ";
    cin>>n;
    cout<<"enter value of k : ";
    cin>>k;
    int arr[n];
    cout<<"enter elements : ";
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<"Elements having frequency greater than "<<n/k<<" are :"<<endl;
    NbyK_occurences2(arr,n,k);
    return 0;
}