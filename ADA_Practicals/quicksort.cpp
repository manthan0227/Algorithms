#include<bits/stdc++.h>
using namespace std;

int partition(int a[], int low, int high){
    int pivot = a[high];
    int i = (low-1);
    for(int k=low;k<=high-1;k++){
        if(a[k]<=pivot){
            i++;
            swap(a[k], a[i]);
        }
    }
    swap(a[i+1], a[high]);
    return (i+1);
}

void quicksort(int a[], int low, int high){
    if(low<high){
        int par = partition(a, low, high);
        quicksort(a, low, par-1);
        quicksort(a, par+1, high);
    }
}
int main(){ 
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    cout<<"Enter the elements of the array: ";
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quicksort(a, 0, n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}

/*input
6
12 11 13 5 6 7
*/

