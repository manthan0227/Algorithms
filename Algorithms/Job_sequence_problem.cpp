#include<bits/stdc++.h>
using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

bool cmp(Job a,Job b){
    return (a.profit>b.profit);
}

void Job_schedulling(Job person[],int n){
    sort(person,person+5,cmp);

    int result[n];
    bool slot[n];

    for(int i=0;i<n;i++){
        slot[i] = false;
    }
    for(int i=0;i<n;i++){
        for(int j=min(n,person[i].deadline)-1;j>=0;j--){
            if(slot[j]==false){
                slot[j]=true;
                result[j] = i;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<person[result[i]].id<<",";
        }
    }
}
int main(){
    Job person[5];
    char Job_id;
    int Job_deadline;
    int Job_Profit;
    for(int i=0;i<5;i++){
        cin>>Job_id>>Job_deadline>>Job_Profit;
        person[i].id = Job_id;
        person[i].deadline = Job_deadline;
        person[i].profit = Job_Profit;
    }
    Job_schedulling(person,5);
    return 0;


}