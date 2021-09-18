#include<bits/stdc++.h>
using namespace std;
 
int v, e;
void DFS(int node, vector<int>adj[], vector<bool>&vis, vector<int>&dfs){
    vis[node]=1;
    dfs.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            DFS(it, adj, vis, dfs);
        }
    }
}

vector<int> BFS(vector<int>adj[], vector<bool>&vis){
    vector<int>bfs;
    for(int i=1;i<v+1;i++){
        if(!vis[i]){
            vis[i] = 1;
            queue<int>q;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                bfs.push_back(node);
                q.pop();
                for(auto it: adj[node]){
                    if(!vis[it]){
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfs;
}

int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    cout<<"Enter the no. of vertices and edges: "<<endl;
    cin>>v>>e;
    vector<int>adj[v+1];
    cout<<"Enter the edges between the vertices: "<<endl;
    for(int i=0;i<e;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }   
    vector<bool>vis(v+1, 0); vector<int>dfs;
    for(int i=1;i<v+1;i++){
        if(!vis[i])
            DFS(i, adj, vis , dfs);
    }
    cout<<"Nodes after appling DFS: ";
    for(auto it: dfs){
        cout<<it<<" ";
    }
    cout<<endl;
    vector<bool>vist(v+1, 0);
    cout<<"Nodes after appling BFS: ";
    vector<int>bfs = BFS(adj, vist);
    for(auto it: bfs){
        cout<<it<<" ";
    }



    return 0;
}

/*
input 

7 6
1 2
2 3
3 6
6 7
2 7
4 5
*/