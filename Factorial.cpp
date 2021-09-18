#include<bits/stdc++.h>
using namespace std;

int iterative(int n){
    int fct=1;
    for(int i=1;i<=n;i++){
        fct*=i;
    }
    return fct;
}
int  recursion(int n){
    if(n==0||n==1){
        return 1;
    }
    return n*recursion(n-1);
}

int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int n;
    cout<<"Enter the number: "<<endl;
    cin>>n;
    cout<<"Factorial by iterative method: " << iterative(n)<<endl;
    cout<<"Factorial by recursive method: "<<  recursion(n)<<endl;
    return 0;
}