/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-22
 * @brief https://leetcode-cn.com/problems/valid-parentheses/
 * 
 * 解决思路：
 * 栈
 */

#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
private:
    unordered_map<char, char> parentheses = {{'(', ')'}, {'{', '}'}, {'[', ']'}}; 
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for(int i = 0; i < s.size(); i++) {
            if (parentheses.find(s[i]) != parentheses.end()) { // find
                char_stack.push(s[i]);
            } else {
                if (char_stack.empty() == 1) return false; // 栈为空

                if (s[i] ==  parentheses[char_stack.top()]) {
                    char_stack.pop();
                } else {
                    return false;
                }
            }
            // cout << s[i] << endl;
        }
        if (char_stack.empty() == 0) return false; // 栈不为空

        return 1;
    }
};

int main(int argc, char const *argv[])
{
    string s = "()[]{}";
    string s1 = "([)]";
    string s2 = "{[]}";
    string s3 = "]";
    Solution *solution = new Solution();
    cout << solution->isValid(s) << endl; // 1
    cout << solution->isValid(s1) << endl; // 0
    cout << solution->isValid(s2) << endl; // 1
    cout << solution->isValid(s3) << endl; // 0
    return 0;
}