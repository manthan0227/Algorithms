#include<bits/stdc++.h>
using namespace std;

class Graph{
    map<int,bool>visited;
    map<int,list<int>>adj;

    public:
        void addEdge(int u,int v){
            adj[u].push_back(v);
        }

        void DFS(int s){
            visited[s] = true;
            cout<<s<<" ";
            list<int> :: iterator i;
            for(i=adj[s].begin();i!=adj[s].end();i++){
                if(visited[*i]==false){
                    DFS(*i);
                }
            }

        }

};

int main(){
    int V,E;
    cout<<"Enter the numbers of vertexs and edges::";
    cin>>V>>E;
    
    int u,v;
    Graph g;
    for(int i=0;i<E;i++){
        cin>>u>>v;  
        g.addEdge(u,v);
    }
    g.DFS(1);
    return 0;
}