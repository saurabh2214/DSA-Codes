#include<bits/stdc++.h> 
using namespace std; 

void checkCycle(vector<int> adj[],int V)//Using BFS (kahn Algo)
{
    vector<int> in_degree(V,0);

    for(int u=0;u<V;u++)
    {
        for(int x:adj[u])
            in_degree[x]++;
    }

    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(in_degree[i]==0)
            q.push(i);
    }

    int count=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int x:adj[u])
        {
            if(--in_degree[x]==0)
                q.push(x);
        }
        count++;
    }
    if(count!=V)
        cout<<"There is a Cycle"<<endl;
    else
        cout<<"There is No Cycle"<<endl;
}

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
}

int main() 
{ 
	int V=5;
	vector<int> adj[V];
	addEdge(adj,0, 1); 
    addEdge(adj,4, 1); 
    addEdge(adj,1, 2); 
    addEdge(adj,2, 3); 
    addEdge(adj,3, 1);  
  
    checkCycle(adj,V);

	return 0; 
} 