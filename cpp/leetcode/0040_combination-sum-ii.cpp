#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtrace(vector<int>& nums,int start,int target){
    if(target==0){
        res.push_back(path);
    }
    for(int i=start;i<nums.size();i++){
        if(i>start&&nums[i]==nums[i-1]||target<0) continue;
        path.push_back(nums[i]);
        backtrace(nums,i+1,target-nums[i]);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(),candidates.end());
    backtrace(candidates,0,target);
    return res;
}