#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

string minWindow(string s, string t) {
    int l = 0, r = 0;
    unordered_map<char, int> need, window;
    for (char &c : t) {
        need[c]++;
    }
    int len = INT32_MAX;
    int start = -1;
    auto fn = [&]() -> bool {
        for (auto &x : need) {
            if (window[x.first] < x.second)
                return false;
        }
        return true;
    };
    while (r < s.size()) {
        char c = s[r];
        window[c]++;
        r++;
        while (l < r && fn()) {
            if (r - l < len) {
                len = r - l;
                start = l;
            }
            char d = s[l];
            window[d]--;
            l++;
        }
    }
    return start == -1 ? "" : s.substr(start, len);
}

string minWindow1(string s, string t) {
    int l = 0, r = 0, valid = 0;
    unordered_map<char, int> need, window;
    for (char &c : t) {
        need[c]++;
    }
    int len = INT32_MAX;
    int start = -1;
    while (r < s.size()) {
        char c = s[r];
        window[c]++;
        if (window[c] <= need[c]) {
            valid++;
        }
        r++;
        while (l < r && valid == t.size()) {
            if (r - l < len) {
                len = r - l;
                start = l;
            }
            char d = s[l];
            window[d]--;
            if (window[d] < need[d]) {
                valid--;
            }
            l++;
        }
    }
    return start == -1 ? "" : s.substr(start, len);
}

int main() {
}