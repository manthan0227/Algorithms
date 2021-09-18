#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
int memoization(int a[],int i, int j){
    if(i==j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    dp[i][j] = INT_MAX;
    for(int k=i;k<j;k++){
        dp[i][j] = min(dp[i][j], memoization(a, i, k)+memoization(a, k+1, j)+a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];
}
int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    cout<<"Enter the size of the array: ";
    int n;
    cin>>n;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp, -1, sizeof(dp));
    int num_of_operations = memoization(a, 1, n-1);
    cout<<num_of_operations<<endl;
    return 0;
}

/*
input
5
40 20 30 10 30
*/
