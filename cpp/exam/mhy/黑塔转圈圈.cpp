#include<iostream>
#include<vector>

using namespace std;

int main() {
   int T;
   cin >> T;
   while (T--) {
       int n;
       cin >> n;
       vector<bool> trigger(n, false);
       vector<int> hp;
       vector<int> ref;
       for (int i = 0; i < n; i++) {
           int x;
           cin >> x;
           ref.push_back(x);
           hp.push_back(x);
       }
       int e, r;
       cin >> e >> r;
       int cnte = 0, cntr = 0;
       bool alldead = true;
       do {
           alldead = true;
           cnte++;
           int t=0;
           for (int i = 0; i < n; i++) {
               hp[i] -= e;
               if (!trigger[i] && hp[i] * 2 < ref[i]) t++;
               if (hp[i] > 0) alldead = false;
           }
           for (; !alldead && t > 0;t--) {
               alldead = true;
               cntr++;
               for (int i = 0; i < n; i++) {
                   hp[i] -= r;
                   if (!trigger[i] && hp[i] * 2 < ref[i]) t++;
                   if(hp[i]>0) alldead = false;
               }
           }
       } while (!alldead);
       cout<<cnte<<" "<<cntr;
   }
}

/*
3
5
100 50 60 80 70
25 10
5
100 50 60 80 70
20 20
5
100 200 300 4000 5000
50 1000

2 5
2 3
1 5
*/