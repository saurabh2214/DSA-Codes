#include <bits/stdc++.h>

using namespace std;


void BFSDis(vector<int> adj[],int s,bool visited[])
{
    queue <int> q;
    visited[s]=true;
    q.push(s);
    while(q.empty()==false)
    {
        int u=q.front();
        q.pop();
        cout<<u<<" ";
        for(int v:adj[u])
        {
            if(visited[v]==false)
            {
                visited[v]=true;
                q.push(v);
            }
        }
    }
}
/*int*/ void BFS(vector<int> adj[],int v)   //commented Part is Used count the number of island(disconnected graphs)
{
    bool visited[v+1]; // int count=0;
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false){
            BFSDis(adj,i,visited);// count++;
        }
            
    }
    // return count;
}

void addEdge(vector<int> adj[],int v,int u)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

//  void printGraph(vector<int> adj[],int v)
// {
//     for(int i=0;i<v;i++)
//     {
//         for(int x: adj[i] )
//         {
//             cout<<i<<"-"<<x<<" ";
//         }
//         cout<<endl;
//     }
// }

int main()
{
    int v=7;
    vector<int> adj[v];
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,1,3);
    addEdge(adj,2,3);
    addEdge(adj,4,5);
    addEdge(adj,4,6);
    addEdge(adj,5,6);
    // printGraph(adj,v);
    cout<<endl;
    
    /*int a = */BFS(adj,v);
    
    // cout<<"No of island in graph are - "<<a<<endl;   //super Important stuff asked in interviews
    
    
    return 0;
}

