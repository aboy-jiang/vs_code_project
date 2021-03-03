/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-01
 * @brief https://leetcode-cn.com/problems/permutations/
 * 
 * 解决思路：动态规划
 * nums = [1, 2, 3]
 * dp[0] = [1]
 * dp[1] = 将2插入dp[0]，dp为[[2, 1], [1, 2]]
 * dp[2] = 将3插入dp[1]，dp为[[3, 2, 1], [2, 3, 1], [2, 1, 3], [3, 1, 2], [1, 3, 2], [1, 2, 3]]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> dp;
        int n = nums.size();
        if (n == 0) return dp;

        // 初始化第1个数据
        vector<int> item;
        item.push_back(nums[0]);
        dp.push_back(item);
        
        // 从第2个开始，逐个插入数据
        for (int i = 1; i < n; i++) {
            dp = insertNum(nums[i], dp);
        }        
        return dp;
    }

    vector<vector<int>> insertNum(int num, vector<vector<int>> dp) {
        vector<vector<int>> dp_new;
        for (int i = 0; i < dp.size(); i++) { // 将num插入每1个item中
            int insert_position = dp[i].size() + 1; // item的插入位置
            for (int j = 0; j < insert_position; j++) { // 追个将num插入item中
                vector<int> item = vector<int>(dp[i]); // 每次插入都会生成一个新的item
                item.insert(item.begin() + j, num);
                dp_new.push_back(item); // 插入item到dp中
            }
        }    
        return dp_new;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3};
    Solution *solution = new Solution();
    vector<vector<int>> dp = solution->permute(nums);
    for (int i = 0; i < dp.size(); i++) {
        vector<int> item = dp[i];
        for (int j = 0; j < item.size(); j++) {
            cout << item[j] << " ";
        }
        cout << endl;
    }
    return 0;
}