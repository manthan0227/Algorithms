#include<bits/stdc++.h>
using namespace std;

void primsAlgo(int src,vector<pair<int,int>>adj[], int v, int e){
    int key[v];
    int parent[v];
    bool mstset[v];
    for(int i=0;i<v;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mstset[i] = false;
    }

    key[src] = 0;
    for(int cnt=0;cnt<v-1;cnt++){
        int mn = INT_MAX,u;
        for(int x=0;x<v;x++){
            if(mstset[x]==false && key[x]<mn){
                mn = key[x];
                mstset[x] = true;
                u = x;
            }
        }
        mstset[u] = true;
        for(auto it: adj[u]){
            int y = it.first;
            int w = it.second;
            if(mstset[y]==false && w<key[y]){
                parent[y] = u;
                key[y] = w;
            }
        }
    }
    int cost=0;
    for(int i=0;i<v;i++){
        cost+=key[i];
    }
    cout<<"Minimum cost determine by the prim's algorithm: "<<cost<<endl;
    for(int i=0;i<v;i++){
        cout<<parent[i]<<"->"<<i<<endl;
    }
}

int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int v, e;
    cout<<"Enter the no. of vertices and edegs: "<<endl;
    cin>>v>>e;
    vector<pair<int,int>>adj[v];
    cout<<"Enter the edges and weights between vertices: ";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    primsAlgo(0, adj, v, e);

    return 0;
}

/*
prims input
5 6
0 1 2
1 2 3
1 4 5
2 4 7
1 3 8
0 3 6

*/
