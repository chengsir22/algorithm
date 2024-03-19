#include<iostream>

using namespace std;

const int N = 1e5+10;
int nums[N];
int sz;

void down(int u){
    int t =u;
    if(u*2<=sz&&nums[u*2]<nums[t]) t=u*2;
    if(u*2+1<=sz&&nums[u*2+1]<nums[t]) t=u*2+1;
    if(t!=u){
        swap(nums[u],nums[t]);
        down(t);
    }
}

void up(int u){
    while(u/2 &&nums[u]<nums[u/2]){
        swap(nums[u],nums[u/2]);
        u>>=1;
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
    }
    sz = n;
    for(int i=n/2;i>0;i--){
        down(i);
    }

    while(m--){
        cout<<nums[1]<<" ";
        nums[1] = nums[sz];
        sz--;
        down(1);
    }
}