/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-19
 * @brief https://leetcode-cn.com/problems/3sum/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;

        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int first = 0; first < n; first++) {
            
            if(first > 0 && nums[first] == nums[first - 1]) continue; // 从第2个元素开始，如果元素值和前一个元素值相同，则跳过

            int third = n - 1; // third初始值为指向数组最右端
            for(int second = first + 1; second < n; second++) {

                if(second > first + 1 && nums[second] == nums[second - 1]) continue; // 从第2个元素开始，如果元素值和前一个元素值相同，则跳过

                while(second < third && nums[first] + nums[second] + nums[third] > 0)
                    third--;
                
                if (second == third) break;

                if (nums[first] + nums[second] + nums[third] == 0) 
                    result.push_back({nums[first], nums[second], nums[third]});
            }
        }

        return result;
    }
};

void printMatrix(vector<vector<int>> &matrix) {
    cout << "[";
    for(auto &i : matrix) {
        cout << "[ ";
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << "]";
    }
    cout << "]";
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution *solution = new Solution();
    vector<vector<int>> result = solution->threeSum(nums);
    printMatrix(result);
    return 0;
}