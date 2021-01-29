/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-01-19
 * @brief https://leetcode.com/problems/two-sum/
 * 
 * 解决思路：
 * 将数组中的数值（value）和位置角标（index）对调存储在map中。
 * 然后数值相减就可以看成是位置角标相减。
 * 然后使用相减后的角标位置作为key在map中检索即可。
 * 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            int a = nums[i];
            int b = target - a;
            if (map.find(b) == map.end()) { // If no such element is found, past-the-end (see end()) iterator is returned
                map[a] = i;
            } else {
                result.push_back(map[b]);
                result.push_back(i);
            }
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution *s = new Solution(); 
    vector<int> result = s->twoSum(nums, target);
    for (const int& i : result)
        cout << i << ' ';
    return 0;
}
