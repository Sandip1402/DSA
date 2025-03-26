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
int BFSdis(vector<int>adj[], int V)
{
    bool visited[V];
    int count_dis=0;
    for(int i=0; i<V; i++)
        visited[i]=false;
    for(int i=0; i<V; i++)
    {
        if(visited[i]==false)
        {
            BFS(adj, visited, i);
            count_dis++;
        }
    }
    return count_dis;
}
void addedge(vector<int>adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    int v,edge,skip;
    cout<<"enter no. of edges : ";
    cin>>edge;
    v=edge+1; // in undirected graph
    vector<int>adj[v];
    for(int i=0; i<=edge; i++)
    {
        cout<<"enter 1 if there is no edge for "<<i<<"th vertex : ";
        cin>>skip;
        if(skip!=1)
        {        
            cout<<"enter edge : "<<i<<"-->";
            int m;
            cin>>m;
            addedge(adj,m,i);
        }
        else
            continue;
    }
    cout<<"\nno. of disconnected graph is : "<<BFSdis(adj,v);
    return 0;
}