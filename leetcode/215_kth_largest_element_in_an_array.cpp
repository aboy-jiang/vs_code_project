/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-12
 * @brief https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * 
 * 解决思路：
 * 快速排序 -> 快速选择
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 随机快速排序
    int randomPartition(vector<int>& nums, int l, int r) {
        int randomIndex = rand() % (r - l + 1) + l; // [l, r]范围内的随机数
        swap(nums[randomIndex], nums[r]);
        return partition(nums, l, r);
    }

    // 快速排序中的分割操作
    int partition(vector<int>& nums, int l, int r) {
        int pivot = r; // 选取最后一个为主元

        while (1) {
            while (l < r && nums[l] <= nums[pivot]) l++;
            while (l < r && nums[r] >= nums[pivot]) r--;
            if (l < r) {
                swap(nums[l], nums[r]);
            } else {
                swap(nums[l], nums[pivot]);
                break;
            }
        }
        return l;
    } 

    int quickSelect(vector<int>& nums, int l, int r, int index) {
        int center_index = randomPartition(nums, l, r);
        if (center_index == index) {
            return nums[center_index];
        } else {
            return index < center_index ? quickSelect(nums, l, center_index - 1, index) : quickSelect(nums, center_index + 1, r, index);
        }
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
};

int main(int argc, char const *argv[])
{
    // vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    // int k = 4;
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution *solution = new Solution();
    cout << solution->findKthLargest(nums, k) << endl;
    return 0;
}
