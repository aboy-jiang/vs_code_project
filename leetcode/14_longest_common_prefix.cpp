/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-08
 * @brief https://leetcode-cn.com/problems/longest-common-prefix/
 * 
 * 解决思路：
 * 纵向遍历，有两个结束条件：1、最后一个字符和第一个字符不相等；2、到达字符串结尾。
 */

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }
        
        int str0_len = strs[0].length();
        int strs_count = strs.size();

        char c;
        for (int i=0; i<str0_len; i++) {
            c = strs[0][i];
            for (int j = 1; j<strs_count; j++) {
                if(strs[j][i] != c || strs[j].size() == i) { 
                    return strs[0].substr(0, i);
                }
            }
        }
        
        return strs[0];
    }
};

int main(int argc, char const *argv[])
{
    vector<string> strs = {"flower","flow","flight"};
    vector<string> strs1 = {"dog","racecar","car"};   
    Solution *solution = new Solution();
    cout << solution->longestCommonPrefix(strs) << endl;
    cout << solution->longestCommonPrefix(strs1) << endl;
    return 0;
}