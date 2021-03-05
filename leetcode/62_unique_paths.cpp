/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-05
 * @brief https://leetcode-cn.com/problems/unique-paths/
 * 
 * 解决思路：
 * 排列组合问题
 * A(m, n) = m! / (m-n)!
 * C(m, n) = A(m, n) / n!
 * 
 * 本题目从start到end共需要走m + n - 2步，其中向左m-1步，向下n-1步
 * 确定任意m-1步向左，既可确定最终路线
 * 
 * 但是本题目要求1 <= m,n <= 100
 * 而100! = 9.332622e+157 会有越界问题，因此需要针对简化计算
 * 
 * C(m, n) = A(m, n) / n! = m * (m-1) * ... * (m-n+1) / (m-n) * m(m-n-1) * ... * 1
 */

#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:    
//     // n的阶乘算法
//     int factorial(int n) {
//         int result = 1;
//         for (int i = n; i >= 1; i--) {
//             result *= i;
//         }
//         return result;
//     }
//     // A(m, n)
//     int A(int m, int n) {
//         return factorial(m) / factorial(m - n);
//     }

//     // C(m, n)
//     int C(int m, int n) {
//         return A(m, n) / factorial(n); 
//     }
    
//     int uniquePaths(int m, int n) {
//         return C(m + n - 2, m - 1);
//     }
// };

class Solution {
public:
    int64_t uniquePaths(int m, int n) {
        int64_t ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    int m = 33, n = 100;
    Solution *solution = new Solution();
    cout << solution->uniquePaths(m, n) << endl;
    return 0; 
}