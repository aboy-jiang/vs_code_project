/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-19
 * @brief https://leetcode-cn.com/problems/3sum-closest/
 * 
 * 解决思路：
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result, loss = INT32_MAX;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i-1]) continue; // 从第2个元素开始，如何和前面一个重复，则忽略

            for (int j = i+1; j < n - 1; j++) {

                if (j > i+1 && nums[j] == nums[j-1]) continue; // 从第i+2个元素开始，如何和前面一个重复，则忽略
                
                for (int k = j+1; k < n; k++) {
                    int tmp_result = nums[i] + nums[j] + nums[k];
                    int tmp_loss = abs(tmp_result - target);
                    if (tmp_loss < loss) {
                        loss = tmp_loss;
                        result = tmp_result;
                    }
                    // cout << "[" << nums[i] << " " << nums[j] << " " << nums[k] << "]" << loss << " " << nums[i] + nums[j] + nums[k] <<endl;
                    
                    if (loss == 0) return result;
                }  
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 2, 1, -4}; // 2
    int target = 1;

    vector<int> nums1 = {1, 1, 1, 0}; // 2
    int target1 = -100;

    vector<int> nums2 = {1, 2, 4, 8, 16, 32, 64, 128}; // 82
    int target2 = 82;

    Solution *solution = new Solution();
    cout << solution->threeSumClosest(nums, target) << endl;
    cout << solution->threeSumClosest(nums1, target1) << endl;
    cout << solution->threeSumClosest(nums2, target2) << endl;

    return 0;
}