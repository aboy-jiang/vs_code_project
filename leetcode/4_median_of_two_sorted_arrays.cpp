/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-01-22
 * @brief https://leetcode.com/problems/median-of-two-sorted-arrays/
 * 
 * 解决思路：
 * 归并排序，取中位数
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> connect_nums;
        int m = nums1.size(), n = nums2.size();
        int p=0, q=0;
        while (p < m && q < n) {
            if (nums1[p] < nums2[q]) {
                connect_nums.push_back(nums1[p]);
                p++;
            } else {
                connect_nums.push_back(nums2[q]);
                q++;
            }
        }
        if(p < m) {
            while (p < m) {
                connect_nums.push_back(nums1[p]);
                p++;
            }
        } else {
            while (q < n) {
                connect_nums.push_back(nums2[q]);
                q++;
            }
        }
        
        double reslut = 0;

        if ((m + n) % 2 != 0) {
            reslut = connect_nums[(m + n)/2];
        } else {
            reslut = (connect_nums[(m + n)/2] + connect_nums[(m + n)/2 - 1]) / 2.0;    
        }

        return reslut;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums1 = {1};
    vector<int> nums2 = {4};
    Solution *solution = new Solution();
    double result = solution->findMedianSortedArrays(nums1, nums2);
    cout << result;
    return 0;
}