/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-10
 * @brief https://leetcode-cn.com/problems/single-number/
 * 
 * 解决思路：
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (auto num : nums)
            result ^= num;
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 3, 2, 3, 2};
    Solution *solution = new Solution();
    cout << solution->singleNumber(nums) << endl;
    return 0;
}