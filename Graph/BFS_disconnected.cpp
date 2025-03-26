// BFS algorithm for undirected graph
/*
    0---1  3    5   8
     \ /   |   / \ /
      2    4  6   7
*/
#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int>adj[], bool visited[], int s)
{
    queue<int>q;
    q.push(s);
    visited[s]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<< u << " ";
        for(int v: adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
void BFSdis(vector<int>adj[], int V)
{
    bool visited[V];
    for(int i=0; i<V; i++)
        visited[i]=false;
    for(int i=0; i<V; i++)
    {
        if(visited[i]==false) // first prints graph for 0 & marks connected edges as true then prints for i = 4;
        {
            BFS(adj, visited, i);
        }
    }
}
void addedge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int v,j;
    cout<<"enter no. of vertex :";
    vector<int>adj[v];
    for(int i=0; i<v; i++)
    {
        cout<< "enter no. of new edges for vertex - " <<i<<endl;
        cin>>j;
        while(j--)
        {
            cout<<"enter edge :"<<endl;
            int m, n;
            cin>>m;
            cout<<'\t'<<"--->"<<'\t';
            cin>>n;
            addedge(adj,m,n);
        }
    }
    // addedge(adj,0,1);
    // addedge(adj,0,2);
    // addedge(adj,1,0);
    // addedge(adj,1,3);
    // addedge(adj,2,0);
    // addedge(adj,2,3);
    // addedge(adj,3,1);
    // addedge(adj,3,2);
    // addedge(adj,4,5);
    // addedge(adj,4,6);
    // addedge(adj,5,6);
    // addedge(adj,5,4);
    // addedge(adj,6,4);
    // addedge(adj,6,5);
    BFSdis(adj,v);
    return 0;
}