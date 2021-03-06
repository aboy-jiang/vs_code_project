/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-06
 * @brief https://leetcode-cn.com/problems/merge-sorted-array/
 * 
 * 解决思路：
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {  
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int end = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[end] = nums1[i];
                i--;
            } else {
                nums1[end] = nums2[j];
                j--;
            }

            end--;
        }

        while (j >= 0) {
            nums1[end] = nums2[j];
            j--;
            end--;
        }
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nusm2 = {2, 5, 6};
    int m = 3, n = 3;
    Solution *solution = new Solution();
    solution->merge(nums1, m, nusm2, n);
    for (const auto &i : nums1)
        cout << i << endl;
    return 0;
}