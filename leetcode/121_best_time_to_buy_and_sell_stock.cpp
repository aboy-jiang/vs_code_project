/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-08
 * @brief https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
 * 
 * 解决思路：
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0, min_num, max_num;
        for (int i = 0; i < prices.size(); i++) {
            if (i == 0) {
                min_num = prices[0];
                max_num = prices[0];
            } else {
                if (prices[i] < min_num) {
                    min_num = prices[i];
                    max_num = prices[i];
                } else {
                    max_num = max(prices[i], max_num);
                }
                result = max(max_num - min_num, result);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {7, 2, 5, 1, 3, 2};
    Solution *solution = new Solution();
    cout << solution->maxProfit(nums) << endl;
    return 0;
}