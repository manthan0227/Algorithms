#include<bits/stdc++.h>
using namespace std;

void heapify(int a[], int n, int i){
    int largest=i;
    int l = 2*i+1;
    int r = 2*i+2;
    if(l<n && a[l]>a[largest]){
        largest = l;
    }
    if(r<n && a[r]>a[largest]){
        largest = r;
    }
    if(largest!=i){
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void heapsort(int a[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a, n, i);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int a[n];
    cout<<"Enter ele. of the array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    heapsort(a, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}


/*
input
6
12 11 13 5 6 7
*/

