/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-26
 * @brief https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 * 
 * 解决思路：二分查找
 * 居中切一刀，将数组切成两部分，其中必定有一部分是有序的。
 * 左侧有序：中间元素大于左侧第一个元素，反之右侧有序。
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1, mid;
        while (l <= r) {
            mid = (l + r)/2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) { // 左侧有序
                if (nums[0] <= target && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else { // 右侧有序
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    Solution *solution = new Solution();
    cout << solution->search(nums, target) << endl;
    return 0;
}