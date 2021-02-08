/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-08
 * @brief https://leetcode-cn.com/problems/container-with-most-water/
 * 
 * 解决思路：双指针 area = (j-i) * min(height[i], height[j]) 面积 = 底面积 x 高（较小的）
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, result = 0, area; 
        while (i < j) {
            area = (j-i) * min(height[i], height[j]);
            result = max(result, area);

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> height = {2,3,4,5,18,17,6};
    Solution *solution = new Solution();
    cout << solution->maxArea(height) << endl;
    return 0; 
}