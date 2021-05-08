#include<bits/stdc++.h>
using namespace std;

int getMax(int amount[3]){
    int maxInd = 0;
    for(int i=1;i<3;i++){
        if(amount[i]>amount[maxInd]){
            maxInd = i;
        }
    }
    return maxInd;
}

int getMin(int amount[]){
    int minInd = 0;
    for(int i=1;i<3;i++){
        if(amount[i]<amount[minInd]){
            minInd = i;
        }
    }
    return minInd;
}

int minOf2(int x,int y){
    return (x<y) ? x : y;
}

void cashFlow(int amount[]){

    int maxCredit = getMax(amount),maxDebit = getMin(amount);
    if(amount[maxCredit]==0 && amount[maxDebit]==0){
        return;
    }

    int min = minOf2(-amount[maxDebit],amount[maxCredit]);
    amount[maxCredit] -= min;
    amount[maxDebit] += min;

    cout<<maxDebit<<"->"<<maxCredit<<"="<<min<<endl;
    cashFlow(amount);
}

void cashFlowBTperson(int g[][3]){
    int amount[3]={0};
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            amount[i] += (g[j][i] - g[i][j]);
        }
    }

    cashFlow(amount);

}

int main(){
    int g[][3]={{0,5000,2000},
                {0,0,0},
                {0,1000,0}};
    cashFlowBTperson(g);

    return 0;
}