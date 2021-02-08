/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-05
 * @brief https://leetcode-cn.com/problems/reverse-integer/
 * 
 * 解决思路：
 * pow函数控制边界
 * 求余、整除反转数字
 */

#include <iostream>
#include <math.h>
using namespace std;

class Solution { 
public:
    int reverse(int x) {
        int result = 0, i;
        while (x != 0)
        {
            i = x % 10;
            if (result > INT32_MAX/10 || result < INT32_MIN/10) {
                return 0;
            } 
            result = 10*result + i;
            x /= 10;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int x = -123;
    Solution *solution = new Solution();
    cout << solution->reverse(x);
    return 0;
}
