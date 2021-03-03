/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-03
 * @brief https://leetcode-cn.com/problems/spiral-matrix/
 * 
 * 解决思路：
 * 模拟旋转遍历，边界控制
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int direction = 0;// 0 - right, 1 - down, 2 - left, 3 - up 
        int row_begin = 0, colum_begin = 0, row_end = matrix.size() - 1, colum_end = matrix[0].size() - 1; // 核心控制变量：4个变量确定一个矩形
        while (row_begin <= row_end && colum_begin <= colum_end) {
            switch (direction) {
            case 0: {
                for (int i = colum_begin; i <= colum_end; i++)
                    result.push_back(matrix[row_begin][i]);
                
                row_begin++;
                direction = 1;
            }
                break;
            case 1: {
                for (int i = row_begin; i <= row_end; i++)
                    result.push_back(matrix[i][colum_end]);
                
                colum_end--;
                direction = 2;
            }
                break;
            case 2: {
                for (int i = colum_end; i >= colum_begin; i--)
                    result.push_back(matrix[row_end][i]);

                row_end--;
                direction = 3;
            }
                break;
            case 3: {
                for (int i = row_end; i >= row_begin; i--)
                    result.push_back(matrix[i][colum_begin]);
                
                colum_begin++;
                direction = 0;
            }
                break;                    
            }
        }
        
        return result;
    }
};

int main(int argc, char const *argv[])
{
    // vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    Solution *solution = new Solution();
    vector<int> result = solution->spiralOrder(matrix);
    for (int i = 0; i <  result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}