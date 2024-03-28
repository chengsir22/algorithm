#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS(vector<int> &nums) {
    int res = 0;
    vector<int> top(nums.size());
    for (int i = 0; i < nums.size(); i++) {
        int poker = nums[i];
        // 左闭右开
        int l = 0, r = res;
        while (l < r) {
            int mid = (l + r) / 2;
            if (top[mid] >= poker) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if(l==res) res++;
        top[l] = poker;
    }
    return res;
}

int lengthOfLIS1(vector<int> &nums) {
    vector<int> dp(nums.size(), 1);
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < dp.size(); i++) {
        res = max(res, dp[i]);
    }
    return res;
}