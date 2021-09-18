#include<bits/stdc++.h>
using namespace std;

int recursion(string x, string y, int n, int m){
    if(n==0 || m==0){
        return 0; 
    }
    if(x[n-1]==y[m-1]){
        return 1+recursion(x, y, n-1, m-1);
    }
    else{
        return max(recursion(x, y, n, m-1), recursion(x, y, n-1, m));
    }
}

int topDown(string x, string y, int n, int m,vector<vector<int>>&s){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(x[i-1]==y[j-1]){
                s[i][j] = 1 + s[i-1][j-1];
            }
            else{
                s[i][j] = max(s[i][j-1], s[i-1][j]);
            }
        }
    }
    return s[n][m];
}

int memoization(string x, string y, int n, int m,vector<vector<int>>&t){
    if(n==0 || m==0){
        return 0;
    }
    if(t[n][m]!=-1){
        return t[n][m];
    }
    if(x[n-1]==y[m-1]){
        return t[n][m] = 1 + memoization(x, y, n-1, m-1, t);
    }
    else{
        return t[n][m] = max(memoization(x, y, n, m-1, t), memoization(x, y, n-1, m, t));
    }

}

void printLCS(string x, string y, int n,int m, vector<vector<int>>&s){
    int i=n,j=m;
    string ans="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            ans+=x[i-1];
            i--;
            j--;
        }
        else{
            if(s[i][j-1]>s[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<"Longest Common Subsequence: ";
    cout<<ans<<endl;
}

int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    string s1,s2;
    cout<<"Enter the string value s1 and s2: "<<endl;
    cout<<"s1: ";
    cin>>s1;
    cout<<"s2: ";
    cin>>s2;
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>>s(n+1, vector<int>(m+1, 0));
    vector<vector<int>>t(n+1, vector<int>(m+1, -1));


    int x = recursion(s1, s2, n, m);
    int y = memoization(s1, s2, n, m, t);
    int z = topDown(s1, s2,n, m, s);

    cout<<"Size of the LCS using recursion: "<<x<<endl;
    cout<<"Size of the LCS using memoization: "<<y<<endl;
    cout<<"Size of the LCS using Topdown Approach: "<<z<<endl<<endl;
    printLCS(s1, s2, n, m, s);
    return 0;
}
/*
input:

abcdgh
abedfhl
*/