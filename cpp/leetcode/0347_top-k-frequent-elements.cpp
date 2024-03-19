#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

using pii = pair<int,int>;

vector<int> topKFrequent(vector<int>&nums,int k){
    auto fn = [](pii a,pii b)->bool{
        return a.second<b.second;
    };
    priority_queue<pii,vector<pii>,decltype(fn)> que(fn);
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]++;
    }
    for(auto& x:map){
        que.push({x.first,x.second});
    }
    vector<int>res;
    while(k--){
        res.push_back(que.top().first);
        que.pop();
    }
    return res;
}