#include<bits/stdc++.h>
using namespace std;
void display_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    printf("%d ", arr[i]);
    printf("\n");
}
void bubblesort(int arr[], int n)
{
    int j,i;
    for(i=1; i<n; i++)
    {
        for(j=i; j>0; j--)
        {
            if(arr[j-1]>arr[j])
            {
                int t=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=t;
            }
        }
    }
}
int main()
{
    int arr[] = {4,10,7,3,2,6};
    bubblesort(arr,6);
    display_array(arr,6);
    return 0;
}