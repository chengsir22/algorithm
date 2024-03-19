#include <string>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s,string p){
    vector<int> res;
    if(p.size()>s.size()) return res;
    vector<int> need(26,0),window(26,0);
    for(int i=0;i<p.size();i++){
        need[p[i]-'a']++;
        window[s[i]-'a']++;
    }
    if(need==window){
        res.push_back(0);
    }
    for(int i = p.size();i<s.size();i++){
        window[s[i]-'a']++;
        window[s[i-p.size()]-'a']--;
        if(window==need){
            res.push_back(i-p.size()+1);
        }
    }
    return res;
}


int main() {

}