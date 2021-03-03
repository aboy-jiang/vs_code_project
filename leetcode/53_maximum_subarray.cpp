/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-03
 * @brief https://leetcode-cn.com/problems/maximum-subarray/
 * 
 * 解决思路：
 * 动态规划
 * 数组nums的长度为n，设f(n)为最优解。则：
 * f(1) = nums[0]
 * f(2) = max(f(1) + nums[1], nums[1])
 * ...
 * f(n) = max(f(n-1) + nums[n-1], nums[n-1])
 * result = max(f(1), f(2), ..., f(n))
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result, f;        
        result = nums[0];
        f = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            f = max(f + nums[i], nums[i]);
            result = max(result, f);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution *solution = new Solution();
    cout << solution->maxSubArray(nums) << endl;
    return 0;
}