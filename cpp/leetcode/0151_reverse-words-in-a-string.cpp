#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 板子
vector<string> splite(string s, char sep) {
    int n = s.size();
    vector<string> vec;

    for (int i = 0, j = 0; i <= n; i++) {
        string tmp;
        if (i == n || s[i] == sep) {
            if (j < i) {
                tmp = s.substr(j, i - j);
                vec.push_back(tmp);
            }
            j = i + 1;
        }
    }
    return vec;
}

string reverseWords(string s) {
    auto vec = splite(s, ' ');
    string res;
    for (int i = vec.size() - 1; i >= 0; i--) {
        res += vec[i] + " ";
    }
    if (!res.empty())
        res.pop_back();
    return res;
}

int main() {
    string s;
    getline(cin, s);
    cout << "[" << reverseWords(s) << "]" << endl;
}