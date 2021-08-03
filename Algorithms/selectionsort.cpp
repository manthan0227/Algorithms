#include<bits/stdc++.h>
using namespace std;

void selectionsort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int ind = i;
        for(int j=i+1;j<n;j++){
            if(a[ind]>a[j]){
                ind = j;
            }
        }
        int temp = a[i];
        a[i] = a[ind];
        a[ind] = temp;
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

    selectionsort(a,n);

    return 0;
}