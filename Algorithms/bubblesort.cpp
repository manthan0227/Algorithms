#include<bits/stdc++.h>
using namespace std;

void bubblesort(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
        if(a[i]>a[j]){
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        }
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}


int main(){
    printf("CE-A3\nName : Manthan Nagpurkar\n");
    printf("Enrollment No: 190130107071\n");
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bubblesort(a,n);
    return 0;
}