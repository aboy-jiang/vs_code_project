/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-05
 * @brief https://leetcode-cn.com/problems/string-to-integer-atoi/
 * 
 * 
 */

#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int result = 0;
        int sign = +1, i = 0, n = s.length();
        while (i < n && s[i] == ' ') i++;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = +1;
            i++;
        }
        
        while (i < n && isdigit(s[i])) {
            int last_i = sign * (s[i] - '0');
            if ((result > INT32_MAX/10) || (result == INT32_MAX/10 && last_i > INT32_MAX%10)) {
                return INT32_MAX;
            } else if ((result < INT32_MIN/10) || (result == INT32_MIN/10 && last_i < INT32_MIN%10)) {
                return INT32_MIN;
            } else {
                result = result * 10 + last_i;
            }            
            i++;
        }
        
        return result;
    }
};

bool test(string s, int result) {
    Solution *solution = new Solution();
    return solution->myAtoi(s) == result;
}

int main(int argc, char const *argv[])
{
    string s1 = "42";
    int result1 = 42;

    string s2 = "   -42";
    int result2 = -42;

    string s3 = "4193 with words";
    int result3 = 4193;

    string s4 = "words and 987";
    int result4 = 0;

    string s5 = "2147483648"; // INT32_MAX is 2147483647
    int result5 = INT32_MAX;

    string s6 = "-2147483649"; // INT32_MIN is -2147483648
    int result6 = INT32_MIN;

    cout << test(s1, result1) << endl;
    cout << test(s2, result2) << endl;
    cout << test(s3, result3) << endl;
    cout << test(s4, result4) << endl;
    cout << test(s5, result5) << endl;
    cout << test(s6, result6) << endl;
    
    return 0;
}
