#include <string>
#include <vector>
using namespace std;

void reverseString(vector<char> &s) {
    int n = s.size();
    if(n<=1) return;
    int l=0,r=n-1;
    while(l<r){
        swap(s[l++],s[r--]);
    }
}