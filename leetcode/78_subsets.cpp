/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-05
 * @brief https://leetcode-cn.com/problems/subsets/
 * 
 * 解决思路：
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        
        // 初始化空集
        vector<int> empty;
        result.push_back(empty);

        for (int i = 0; i < nums.size(); i++) {
            int item_size = result.size();
            for (int j = 0; j < item_size; j++) {
                vector<int> new_item(result[j]);
                new_item.push_back(nums[i]);
                result.push_back(new_item);
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution *solution = new Solution();
    vector<vector<int>> dp = solution->subsets(nums);
    for (int i = 0; i < dp.size(); i++) {
        vector<int> item = dp[i];
        for (int j = 0; j < item.size(); j++) {
            cout << item[j] << " ";
        }
        cout << endl;
    }
    return 0;
}