#include<bits/stdc++.h>
using namespace std;
// adjacency list 
// 0 -- 1
//  \  / \  
//    2   3
void addedge(vector<int>arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
void print_graph(vector<int>arr[], int v)
{
    for(int i=0; i<v; i++)
    {
        for(int x: arr[i])
        {
            cout << x <<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int v = 4;
    vector<int>arr[v];
    addedge(arr,0,1);
    addedge(arr,0,2);
    addedge(arr,1,2);
    addedge(arr,1,3);
    print_graph(arr,v);
    return 0;
}