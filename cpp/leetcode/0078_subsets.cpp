#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> res;
vector<int> path;

void backtrace(int start,vector<int>& nums){
    res.push_back(path);
    for(int i=start;i<nums.size();i++){
        path.push_back(nums[i]);
        backtrace(i+1,nums);
        path.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>&nums){
    backtrace(0,nums);
    return res;
}

int main(){

}