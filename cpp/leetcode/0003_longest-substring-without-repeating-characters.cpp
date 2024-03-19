#include <string>
#include<unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_set<char> set;
    int l=0,r=0;
    int res = 0;
    while(r<s.size()){
        while(set.count(s[r])){
            set.erase(s[l++]);
        }
        set.insert(s[r++]);
        res = max(res,r-l);
    }
    return res;
}