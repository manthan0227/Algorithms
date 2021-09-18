#include<bits/stdc++.h>
using namespace std;

struct node{
    int u,v,w;
    node(int first, int second, int weight){
        u = first;
        v = second;
        w = weight;
    }
};

bool comp(node a, node b){
    return a.w<b.w;
}

int findpar(int u, vector<int>&parent){
    if(parent[u]==u) return u;
    return findpar(parent[u], parent);
}

void unionn(int u, int v, vector<int>&parent, vector<int>&rank){
    u = findpar(u, parent);
    v = findpar(v, parent);
    if(rank[u]<rank[v]){
        parent[u] = v; 
    }
    else if(rank[v]<rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}

void kruskalAlgo(vector<node>edges, int v, int e){
    sort(edges.begin(), edges.end(),comp);
    vector<int>parent(v);
    for(int i=0;i<v;i++){
        parent[i] = i;
    }
    vector<int>rank(v,0);
    
    int cost=0;
    vector<pair<int,int>>mstset;
    for(auto it: edges){
        if(findpar(it.v, parent)!=findpar(it.u, parent)){
            cost += it.w;
            mstset.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout<<"Minimum cost determine by the kruskal algorithm: "<<cost<<endl;
    for(auto it: mstset){
        cout<<it.first<<"->"<<it.second<<endl;
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
    vector<node>edges;
    cout<<"Enter the edges and weights between vertices: ";
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back(node(u, v, w));
    }
    kruskalAlgo(edges, v, e);
    return 0;
}

/*kruskal input
5 6
0 1 2
1 2 3
1 4 5
2 4 7
1 3 8
0 3 6
*/

