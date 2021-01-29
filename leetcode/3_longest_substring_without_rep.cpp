/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-01-21
 * @brief https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * 
 * 解决思路：
 * 字符串中字符（value）和存储位置（index）对调存储在map中
 * 
 */

#include <iostream>
#include <unordered_map>
#include <string.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max_len = 0; // 最大子串长度
        int last_index = -1; // 最后一个重复的字符的位置
        for (int i = 0; i < s.length(); i++) {
            if (map.find(s[i]) != map.end()) { // 如果在map中发现重复字符
                int index = map[s[i]]; // 重复字符位置
                if (index > last_index) { // 重复字符的位置有可能比last_index小，比如：abba当遍历到最后一个a的时候，此时index=0, last_index=1
                    last_index = index;
                }
            }            
            
            int len = i - last_index;
            if (len > max_len) max_len = len;

            map[s[i]] = i;
        } 
        return max_len;
    }
};

int main(int argc, char const *argv[])
{
    string s = "dvdf"; 
    Solution *solution = new Solution();
    int result = solution->lengthOfLongestSubstring(s);
    cout << result;

    return 0;
}