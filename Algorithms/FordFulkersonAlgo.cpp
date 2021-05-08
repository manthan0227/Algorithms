#include<bits/stdc++.h>
#include<limits.h>
#include<string.h>
#define V 6
using namespace std;

bool bfs(int rg[V][V],int s,int t,int parent[]){
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    queue<int>q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v = 0;v<V;v++){
            if(visited[v] == false && rg[u][v]>0){
                if(v==t){
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                visited[v] = true;
                parent[v] = u;
            }
        }
    }


    return false;
}

int fordFulkerson(int g[][V],int s,int t){
    int u,v;
    int rg[V][V];
    for(u=0;u<V;u++){
        for(v=0;v<V;v++){
            rg[u][v] = g[u][v];
        }
    }

    int parent[V];

    int max_flow = 0;
    while(bfs(rg,s,t,parent)){
        int path_flow = INT_MAX;
        for(v = t;v!=s;v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow,rg[u][v]);
        }

        for(v = t;v!=s;v=parent[v]){
            u = parent[v];
            rg[u][v]-= path_flow;
            rg[v][u]+= path_flow;

        }
        max_flow += path_flow;
    }
    return max_flow;

}

int main(){
    int v[V][V] = {{0,16,13,0,0,0},
                    {0,0,10,12,0,0},
                    {0,4,0,0,14,0},
                    {0,0,9,0,0,20},
                    {0,0,0,7,0,4},
                    {0,0,0,0,0,0}};

    cout<<"The maximum possible flow is = "<<fordFulkerson(v,0,5);
    return 0;
}