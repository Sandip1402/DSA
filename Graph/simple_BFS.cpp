// breadth first search in graph
#include<bits/stdc++.h>
using namespace std;
void breadthfirstsearch(vector<int>adj[], int V, int s)
{
    bool visited[V];
    for(int i=0; i<V; i++)
    {
        visited[i]=false;
    }
    queue<int>q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adj[u])
        {
            if(visited[v] == false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void addedge(vector<int>arr[], int u, int v)
{
    arr[u].push_back(v);
    arr[v].push_back(u);
}
int main()
{
    int v = 4;
    vector<int>arr[v];
    addedge(arr,0,1);
    addedge(arr,0,2);
    addedge(arr,1,2);
    addedge(arr,1,3);
    // cout<<arr[0][0]<<endl; 
    breadthfirstsearch(arr,v,0);
    return 0;
}