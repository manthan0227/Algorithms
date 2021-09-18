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
    bubblesort(a,n);
    return 0;
}