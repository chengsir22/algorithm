#include <string>
#include <unordered_map>
using namespace std;

bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size())
        return false;
    unordered_map<char, int> need, window;
    for (auto &c : s1) {
        need[c]++;
    }
    for (int i = 0; i < s1.size(); i++) {
        window[s2[i]]++;
    }
    auto fn = [&]() {
        for (auto &c : need) {
            if (window[c.first] != c.second)
                return false;
        }
        return true;
    };
    if (fn())
        return true;
    for (int i = s1.size(); i < s2.size(); i++) {
        window[s2[i]]++;
        window[s2[i - s1.size()]]--;
        if (fn())
            return false;
    }
    return true;
}