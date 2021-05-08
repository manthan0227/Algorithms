#include<bits/stdc++.h>
#include<queue>
using namespace std;

bool Bipartion(int g[][3],int s,int colorArr[]){
    colorArr[s] = 1;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        s = q.front();
        q.pop();
        for(int i=0;i<3;i++){
            if(g[s][i] && colorArr[i]==-1){
                colorArr[i] = 1 - colorArr[s];
                q.push(i);
            }
            else if(g[s][i] && colorArr[i]==colorArr[s]){
                return false;
            }
        }
    }

    return true;
}

bool isBiParition(int g[][3]){

    int colorArr[3];
    for(int i=0;i<3;i++){
        colorArr[i] = -1;
    }

    for(int i=0;i<3;i++){
        if(colorArr[i]==-1){
            if(Bipartion(g,i,colorArr)==false){
                return false;
            }
        }
    }
    return true;
}


bool canBeDividedInTwoClique(int g[][3]){

    int gc[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            gc[i][j] = (i!=j)? !g[i][j] : 0;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<gc[i][j]<<" ";
        }
        cout<<endl;
    }
    return isBiParition(gc);
}

int main(){
    int g[][3] = {{0,1,0},
                 {1,1,1},
                 {0,0,0}};

    canBeDividedInTwoClique(g)?cout<<"YES":cout<<"NO"<<endl;
    return 0; 
}