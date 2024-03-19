#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int> &nums, int val) {
    int n = nums.size();
    int i = 0, j = 0;
    for (; i < n; i++) {
        if(nums[i]!=val){
            nums[j++] = nums[i];
        }
    }
    return j;
}

