#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 2 && nums[i] <= 0; i++) {
        if(i&&nums[i]==nums[i-1])continue;
        int l = i + 1, r = n - 1;
        while (l < r) {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0) {
                l++;
            } else if (sum > 0) {
                r--;
            } else {
                res.push_back({nums[i], nums[l++], nums[r--]});
                while(l<r&&nums[l]==nums[l-1]) l++;
                while(l<r&&nums[r]==nums[r+1]) r--;
            }
        }
    }
    return res;
}

int main() {
    vector<int> sample = {-1,0,1,2,-1,-4};
    auto res = threeSum(sample);
    for(auto nums:res){
        for(auto x:nums){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}