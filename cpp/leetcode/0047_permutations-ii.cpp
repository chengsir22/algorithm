#include <algorithm>
#include <vector>

using namespace std;

vector<vector<int>> res;
vector<int> path;
vector<bool> vis;

void backtrace(vector<int> &nums) {
    if (path.size() == nums.size()) {
        res.push_back(path);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if(vis[i]) continue;
        if (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1])
            continue;
        path.push_back(nums[i]);
        vis[i] = true;
        backtrace(nums);
        path.pop_back();
        vis[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    vis = vector<bool>(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrace(nums);
    return res;
}