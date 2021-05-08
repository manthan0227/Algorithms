#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*adj;

    public:
        Graph(int V,int E){
            this->V = V;
            adj = new list<int>[V];
        }

        void addEdge(int u,int v){
            adj[u].push_back(v);
        }

        void BFS(int s){
            bool *visited = new bool[V];
            for(int i=0;i<V;i++){
                visited[i] = false;
            }
            list<int>queue;
            queue.push_back(s);
            visited[s] = true;

            while(!queue.empty()){
                s = queue.front();
                cout<<s<<" ";
                queue.pop_front();
                list<int> :: iterator i;
                for(i = adj[s].begin();i!=adj[s].end();i++){
                    if(visited[*i]==false){
                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
        }

};


int main(){
    int V,E;
    cout<<"Enter the numbers of vertexs and edges::";
    cin>>V>>E;
    int u,v;
    Graph g(V,E);
    
    for(int i=0;i<E;i++){
        cin>>u>>v;
        g.addEdge(u,v);
    }
    g.BFS(2);

    return 0;
}