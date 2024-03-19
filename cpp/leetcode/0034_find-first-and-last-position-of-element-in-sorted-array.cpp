#include<iostream>
#include<vector>
using namespace std;

vector<int> searchRange(vector<int>&nums,int target){
    vector<int> res;
    int l=0,r=nums.size()-1;
    if(r<0) return {-1,-1};
    while(l<r){
        int mid = l+r>>1;
        if(nums[mid]>=target){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if(nums[l]==target) res.push_back(l);
    else res.push_back(-1);

    l=0,r=nums.size()-1;
    while(l<r){
        int mid = l+r+1>>1;
        if(nums[mid]<=target) l = mid;
        else r=mid-1;
    }
    if(nums[l]==target) res.push_back(l);
    else res.push_back(-1);
    return res;
}
int main(){

}