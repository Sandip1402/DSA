#include<bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int m, int h){
    int left=m-l+1;
    int right=h-m;
    int leftarr[left];
    int rightarr[right];
    for(int i=0;i<left;i++){leftarr[i]=arr[l+i];}
    for(int i=0;i<right;i++){rightarr[i]=arr[m+i+1];}
    int i=0,j=0,k=l;
    while(i<left&&j<right){
        if(leftarr[i]<=rightarr[j]){arr[k++]=leftarr[i++];}
        else{arr[k++]=rightarr[j++];}
    }
    while(i<left){
        arr[k++]=leftarr[i++];
    }
    while(j<right){
        arr[k++]=rightarr[j++];
    }
}
void merge_sort(int arr[], int low, int high){
    int mid;
    if(low<high){
        mid = (low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void display_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    // cout<<("%d ", arr[i]); // doesn't give any error & space
    // cout<<("\n");
    cout<<arr[i]<<" ";
    cout<<endl;
}
int main(){
    int arr[] = {4,10,7,3,2,6};
    merge_sort(arr,0,5);
    display_array(arr,6);
    return 0;
}