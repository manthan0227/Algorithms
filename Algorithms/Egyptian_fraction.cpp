#include<bits/stdc++.h>
using namespace std;

void egytian_fraction(int nr,int dr){
    if(dr==0 || nr==0){
        return;
    }
    if(dr%nr==0){
        cout<<"1/"<<dr/nr;
        return;
    }
    if(nr%dr==0){
        cout<<nr/dr;
        return;
    }
    if(nr>dr){
        cout<<nr/dr<<"+";
        egytian_fraction(nr%dr,dr);
        return;
    }
    int n = dr/nr + 1;
    cout<<"1/"<<n<<"+";
    egytian_fraction(nr*n-dr,n*dr);
    return;
}

int main(){
    int nr,dr;
    cout<<"nr = ";
    cin>>nr;
    cout<<"dr = ";
    cin>>dr;
    egytian_fraction(nr,dr);
    return 0;
}