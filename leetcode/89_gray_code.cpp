/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-08
 * @brief https://leetcode-cn.com/problems/gray-code/
 * 
 * 解决思路：
 * 动态规划
 * f(0) = [0]
 * f(1) = [0, 1]
 * f(2) = [00, 01, 11, 10]
 * ...
 * f(n) = f(n-1), f(n-1)倒序最高位补1]
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        int head = 1;
        for (int i = 1; i <= n; i++) {
            int old_size = result.size();
            for (int j = old_size - 1; j >= 0; j--)
                result.push_back(result[j] + head);
            head <<= 1; // 将head左移1位
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;
    Solution *solution = new Solution();
    vector<int> result = solution->grayCode(n);
    for(int i = 0; i < result.size(); i++)
        cout << result[i] << endl;
    return 0;
}