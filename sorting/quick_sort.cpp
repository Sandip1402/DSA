#include<bits/stdc++.h>
using namespace std;
void display_array(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int partition(int arr[], int low, int high)
{
    int i = low+1;
    int j = high;
    int pivot = arr[low], temp;
    do
    {
        while(arr[i] <= pivot) // finds element greater than pivot
        {
            i++;
        }
        while(arr[j] > pivot) // finds element smaller than pivot
        {
            j--;
        }
        if(i<j) // swap elements until i<j
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }while(i < j);
    temp  = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    // display_array(arr,5);
    return j;
}
void quick_sort(int arr[], int low, int high)
{
    int part_ind;
    if(low < high)
    {
        part_ind = partition(arr,low,high); 
        quick_sort(arr,low,(part_ind)-1);
        quick_sort(arr,(part_ind)+1,high);
    }
}
int main(){
    int arr[] = {2,5,1,4,3};
    quick_sort(arr,0,4);
    display_array(arr,5);
    return 0;
}