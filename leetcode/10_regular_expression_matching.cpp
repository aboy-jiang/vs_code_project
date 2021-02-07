/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-07
 * @brief https://leetcode.com/problems/regular-expression-matching/
 * 
 * 解决思路：
 * 正则表达式基础："."任意一个字符，"x*"多个x字符
 * 动态规划
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size() + 1;
        int n = p.size() + 1;        
        vector<vector<int>> dp(m, vector<int>(n));
        
        
        dp[0][0] = true; // 初始化第1个元素：s和p为两个空字符串时，s中可匹配p
        for (int i=1; i<m; i++) { // 初始化第1列：s不为空，p为空，s中不可以匹配p
            dp[i][0] = false; 
        }
        for (int j=1; j<n; j++) { // 初始化第1行：s为空，p不为空，分两种情况讨论
             if(p[j-1] != '*') {  // 情况1：p中第j个不为*，则不匹配
                dp[0][j] = false;
             } else { // 情况2：p中第j个为*，则看‘x*’之前的p是否匹配
                dp[0][j] = dp[0][j-2];
             }
        }
        
        auto matches = [&](int i, int j) { // 判断s中第i个字符和p中第j个字符是否匹配
            return (s[i-1] == p[j-1] || p[j-1] == '.');
        };
        for (int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if (p[j-1] != '*') { // 如果p中第j个字符不为*，分两种情况讨论。注意：这里p[j-1]表示第j个p
                    if (matches(i, j)) { 
                        dp[i][j] = dp[i-1][j-1];
                    } else {
                        dp[i][j] = false;
                    }
                } else { // 如果p中第j个字符为*
                    if (dp[i][j-2] == true) { 
                        dp[i][j] = true;
                    } else { 
                        if (matches(i, j - 1)) {
                            dp[i][j] = dp[i-1][j]; // ‘x*’匹配多个x的情况（重点、难点）
                        } else {
                            dp[i][j] = false; 
                        }
                    }
                }
            }
        }

        // 打印dp
        // for(int i=0; i<m; i++) {
        //     for (int j=0; j<n; j++) {
        //         cout << dp[i][j] << '\t';
        //     }
        //     cout << endl;
        // }

        return dp[m-1][n-1];
    } 
};

int main(int argc, char const *argv[])
{
    string s1 = "aa", p1 = "a";
    string s2 = "aa", p2 = "a*";
    string s3 = "ab", p3 = ".*"; 
    string s4 = "aab", p4 = "c*a*b";   
    string s5 = "mississippi", p5 = "mis*is*p*.";

    Solution *solution = new Solution();
    cout << solution->isMatch(s1, p1) << endl;
    cout << solution->isMatch(s2, p2) << endl;
    cout << solution->isMatch(s3, p3) << endl;
    cout << solution->isMatch(s4, p4) << endl;
    cout << solution->isMatch(s5, p5) << endl;
    return 0;
}


