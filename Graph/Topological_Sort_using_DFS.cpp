#include<bits/stdc++.h> 
using namespace std; 

void DFS(vector<int> adj[],int u,stack<int> &st,bool visited[])
{
    visited[u]=true;

    for(int v:adj[u])
        if(visited[v]==false)
            DFS(adj,v,st,visited);
    st.push(u);
}

void topologicalSort(vector<int> adj[],int v)
{
    bool visited[v];
    for(int i=0;i<v;i++)
    {
        visited[i]=false;
    }

    stack<int> st;
    for(int i=0;i<v;i++)
    {
        if(visited[i]==false)
            DFS(adj,i,st,visited);
    }

    while(st.empty()==false)
    {
        int a=st.top();
        st.pop();
        cout<<a<<" ";
    }

}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,1, 3); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 4); 
    addEdge(adj,2, 4);  
  
    cout << "Following is a Topological Sort of\n"; 
    topologicalSort(adj,V);

	return 0; 
} 