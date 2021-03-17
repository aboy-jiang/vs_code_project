/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-17
 * @brief https://leetcode-cn.com/problems/assign-cookies/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while(i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) i++;
            j++;
        }
        return i;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> g = {1, 2}, s = {1, 2, 3};
    Solution *solution = new Solution();
    cout << solution->findContentChildren(g, s) << endl;
    return 0;
}