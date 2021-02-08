/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-08
 * @brief https://leetcode-cn.com/problems/integer-to-roman/
 * 
 * 解决思路：
 */

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    map<int, string> romanMap = {
        {1, "I"},
        {4, "IV"},
        {5, "V"},
        {9, "IX"},
        {10, "X"},
        {40, "XL"},
        {50, "L"},
        {90, "XC"},
        {100, "C"},
        {400, "CD"},
        {500, "D"},
        {900, "CM"},
        {1000, "M"},
    };

    string intToRoman(int num) {
        string result = "";

        for (auto i = romanMap.rbegin(); i != romanMap.rend(); i++) {
            int value = i->first;
            string symbol = i->second;
            
            if (num == 0) break;
            while (num >= value) {
                num -=value;
                result += symbol;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    int num = 1994;
    Solution *solution = new Solution();
    cout << solution->intToRoman(num) << endl; 
    return 0;
}