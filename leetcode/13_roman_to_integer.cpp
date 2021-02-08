/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-08
 * @brief https://leetcode-cn.com/problems/roman-to-integer/
 * 
 * 解决思路：
 */

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:    
    map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

    int romanToInt(string s) { 
        int result = 0;
        
        int i=0, j=1, v_i, v_j;
        while (i < s.size()) {
            v_i = romanMap[s[i]];
            v_j = i == s.size() - 1 ? INT_MIN : romanMap[s[j]];
            if (v_i >= v_j) { // 正常情况：前面数字 >= 后面数字
                result += v_i;
                i += 1;
                j += 1;
            } else {
                result += (v_j - v_i);
                i += 2;
                j += 2;
            }
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    string roman = "MCMXCIV";
    Solution *solution = new Solution();
    cout << solution->romanToInt(roman) << endl;
    return 0;
}