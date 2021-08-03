#include<bits/stdc++.h>
using namespace std;

void insertionsort(int a[], int n){
    for(int i=1;i<n;i++){
        int k = a[i];
        int j = i-1;
        while(j>=0 && k<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = k;
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}



int main(){
    printf("CE-A3\nName: Manthan Nagpurkar\n");
    printf("Enrollment No: 190130107071\n");
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    insertionsort(a,n);

    return 0;
}