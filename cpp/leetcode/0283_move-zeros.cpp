#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums) {
    int n = nums.size();
    int slow = 0, fast = 0;
    for (; fast < n;fast++) {
        if(nums[fast]!=0){
            nums[slow++] = nums[fast];
        }
    }
    for(;slow<n;slow++){
        nums[slow]=0;
    }
}