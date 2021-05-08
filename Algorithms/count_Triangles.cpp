#include<bits/stdc++.h>
#define V 5
using namespace std;

int countTriangle(int g[][V],bool Directed){
    int count=0;
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            for(int k=0;k<V;k++){
                if(g[i][j]&&g[j][k]&&g[k][i]){
                    count++;
                }
            }
        }
    }
    if(Directed){
        count/=3;
    }
    else{
        count/=6;
    }
    return count;
}

int main(){

    int dg[V][V] = {{0,1,0,1,0},
                    {0,0,1,0,0},
                    {0,0,0,1,1},
                    {0,1,0,0,0},
                    {0,1,0,0,0}};
    cout<<"Directed Graph has "<<countTriangle(dg,true)<<" Triangles"<<endl;
    return 0;
}