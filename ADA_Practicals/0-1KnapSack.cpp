#include<bits/stdc++.h>
using namespace std;
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
        cin>>wt[i]>>val[i];
    }
    int dp[n+1][W+1];
    for(int i=0;i<n+1;i++){
        for(int j=0;j<W+1;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1]>j){
                dp[i][j] = dp[i-1][j]; 
            }
            else{
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
        }
    }
    cout<<"Total profit: " <<dp[n][W]<<endl;
    return 0;
}


/*
input
3 50
10 60 
20 100
30 120
*/