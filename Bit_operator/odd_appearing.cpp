#include<bits/stdc++.h>
using namespace std;
// counting two odd appearing number in array -- O(n),O(1)
void oddappearing(int arr[], int n)
{
    int x=arr[0];
    for(int i=1; i<n; i++)
        x=x^arr[i];
    cout<<x<<endl;
    int k=(x&(~(x-1))); //k contain the last set bit of x
    cout<<k<<endl;
    int N1=0,N2=0;
    for(int i=0; i<n; i++)
    {
        if((k&arr[i])!=0)
            N1=N1^arr[i];
        else
            N2=N2^arr[i];
    }
    cout<<"The two odd appearing numbers are "<<N1<<","<<N2;
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
    oddappearing(arr,n);
    return 0;
}