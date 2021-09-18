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
    selectionsort(a,n);
    return 0;
}