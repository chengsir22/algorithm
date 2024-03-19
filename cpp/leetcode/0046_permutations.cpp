#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtrace(vector<int> &nums,vector<bool>& vis) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for(int i=0;i<nums.size();i++){
        if(vis[i]) continue;
        path.push_back(nums[i]);
        vis[i]=true;
        backtrace(nums,vis);
        path.pop_back();
        vis[i]=false;
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<bool> vis(nums.size(),false);
    backtrace(nums,vis);
    return res;
}

int main() {
}