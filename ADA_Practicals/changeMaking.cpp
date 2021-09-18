#include<bits/stdc++.h>
using namespace std;

int changeMaking(int a[], int n, int T){
    if(T==0){
        return 1;
    }
    if(T<0){
        return 0;
    }
    if(n<=0 && T>=0){
        return 0;
    }

    return changeMaking(a, n-1, T)+changeMaking(a, n, T-a[n-1]);
}
int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int n, T;
    cout<<"Enter the no. of coins and total cents: ";
    cin>>n>>T;
    int a[n];
    cout<<"Enter the values of the coins: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }   
    int ways = changeMaking(a, n, T);
    cout<<"Number of ways to make T cents: "<<ways<<endl;
    return 0;
}


/*
input
3 4 
1 2 3
*/