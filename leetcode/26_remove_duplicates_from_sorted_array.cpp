/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-25
 * @brief https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        
        int i, j = 1, move_step;
        while (j < n) {
            i = j - 1;
            if (nums[i] == nums[j]) {
                j++;
            } 
            
            move_step = j - (i + 1);
            if (move_step > 0) {
                // 移动元素
                for (int k = j; k < n; k++) {
                    nums[k - move_step] = nums[k];
                }

                n -= move_step; // 减少n

                j = i + 1; // 调整j位置
            } else {
                j++;
            }
        }
        return n;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution *solution = new Solution();
    int n = solution->removeDuplicates(nums);
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}