#include<bits/stdc++.h>
using namespace std;
void fractionalKnapsack(int wt[], int val[], int W, int n){
    int curwt=0;
    double value=0;
    for(int i=0;i<n;i++){
        if(curwt+wt[i]<=W){
            curwt+=wt[i];
            value+=val[i];
        }
        else{
            int r = W - curwt;
            value += val[i]*((double)r/(double(wt[i])));
            break;
        }
    }
    cout<<"Total profit: " <<value<<endl;
}
int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int n,W;
    cout<<"Enter the size of the items and total weight: ";
    cin>>n>>W;
    int wt[n],val[n];
    cout<<"Enter the weight and value of the item: ";
    for(int i=0;i<n;i++){
        cout<<i+1<<". ";   cin>>wt[i]>>val[i];
    }
    fractionalKnapsack(wt, val, W, n);
    return 0;
}

/*
input
3 50
10 60 
20 100
30 120
*/