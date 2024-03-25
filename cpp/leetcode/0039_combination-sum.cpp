#include <vector>
#include <algorithm>
using namespace std;


vector<vector<int>> res;
vector<int> path;

void backtrace(vector<int>& nums,int start,int target){
    if(target == 0){
        res.push_back(path);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=start;i<nums.size();i++){
        path.push_back(nums[i]);
        backtrace(nums,i,target-nums[i]);
        path.pop_back();
    }
}


vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    sort(candidates.begin(),candidates.end());
    backtrace(candidates,0,target);
    return res;
}