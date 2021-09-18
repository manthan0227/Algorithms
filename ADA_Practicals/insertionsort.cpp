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
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    cout<<"Enter the size of the array: "; 
    int n;
    cin>>n;
    cout<<"Enter the elements of the array: ";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    insertionsort(a,n);

    return 0;
}