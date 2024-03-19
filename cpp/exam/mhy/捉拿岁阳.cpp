#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e5;
int a[N],b[N];

int main() {
    int n, m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    int res =0;
    for(int i=0;i<n;i++){
        auto it = upper_bound(a+i,a+n,a[i]);
        int k = it-a;
        for(int j=0;j<m;j++){
            auto it2 = upper_bound(b+j,b+m,b[j]);
            int h = it2-b;
            res+=k*h;
        }
    }
    cout<<res<<endl;
}

/*
3 3
1 2 3
1 1 3

42
*/