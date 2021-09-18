#include<bits/stdc++.h>
using namespace std;
bool linearSearch(int a[], int n, int ele){
    bool find = 0;
    for(int i=0;i<n;i++){
        if(a[i]==ele){
            find =1;
            break;
        }
    }
    return find;
}
bool binarySearch(int a[], int n, int ele){
    int l=0,r=n;
    bool find=0;
    sort(a, a+n);
    while(l<=r){
        int mid = (l+r)/2;
        if(a[mid]==ele){
            find=1;
            break;
        }
        else if(a[mid]>ele){
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return find;
}
int main(){
    time_t now = time(NULL);
    cout<<"Name: Manthan Nagpurkar"<<endl;
    cout<<"Enrollment No: 190130107071"<<endl;
    cout<<ctime(&now)<<endl;
    int n,ele;
    cout<<"Enter the size of the array and find element: ";
    cin>>n>>ele;
    int a[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(linearSearch(a, n, ele) && binarySearch(a, n, ele)){
        cout<<"Element is present"<<endl;
    }
    else{
        cout<<"Element is not present"<<endl;
    }

    return 0;
}