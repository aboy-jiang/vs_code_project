/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-01-26
 * @brief https://leetcode.com/problems/longest-palindromic-substring/
 * 
 * 解决思路：
 * 该问题提复合动态规划问题条件：1）原问题的解里面包含子问题的解；2）子问题的解多次用到。
 */

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        string substring;
        for (int i = n-1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (j == i) {
                    dp[i][j] = 1;
                } else if (j < i + 3) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j]) && (dp[i+1][j-1] == 1);
                }
                
                int substring_len = j - i + 1;
                if (dp[i][j] == 1 && (substring_len  >= substring.length())) { // 如果是回文，且长度大于子回文长度
                    substring = s.substr(i, substring_len);
                } 
            }
        }
        
        // 输出dp[i,j]
        cout << "dp[i,j]\n";
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                cout << dp[i][j] << "\t";                
            }
            cout << "\n";
        }

        return substring;
    }
};


int main(int argc, char const *argv[])
{
    string s = "babad";
    Solution *solution = new Solution();
    cout << solution->longestPalindrome(s);
    return 0;
}
