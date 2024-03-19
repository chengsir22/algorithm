#include <string>

using namespace std;

string Palindrome(string &s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return s.substr(l + 1, r - l - 1);
}

string longestPalindrome(string s) {
    int n = s.size();
    int len = 0;
    string res = "";
    for (int i = 0; i < n; i++) {
        string a = Palindrome(s, i, i);
        string b = Palindrome(s, i, i + 1);
        if(a.size()>len){
            len = a.size();
            res = a;
        }
        if(b.size()>len){
            len = b.size();
            res = b;
        }
    }
    return res;
}