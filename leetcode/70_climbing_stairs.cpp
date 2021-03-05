/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-05
 * @brief https://leetcode-cn.com/problems/climbing-stairs/
 * 
 * 解决思路：
 * 动态规划
 * 爬到第n阶，只能从第n-1或n-2阶爬上来，因此动态规划的转移方程为：
 * f(n) = f(n-1) + f(n-2)
 * 边界条件：
 * 我从第0阶开始爬，f(2) = f(1) + f(0)
 * f(1) = 1
 * f(0) = 1
 * 
 * f(n)只与f(n-1)和f(n-2)有关，利用【滚动数组思想】把空间负责度优化成O(1)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int fn, fn_1 = 1, fn_2 = 1; 
        for (int i = 2; i <= n; i++) {
            fn = fn_1 + fn_2;
            fn_2 = fn_1;
            fn_1 = fn;
        }
        return fn;
    }
};

int main(int argc, char const *argv[])
{
    int n = 2;
    Solution *solution = new Solution();
    cout << solution->climbStairs(n) << endl;
    return 0;
}