/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-03
 * @brief https://leetcode-cn.com/problems/spiral-matrix-ii/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int direction = 0;// 0 - right, 1 - down, 2 - left, 3 - up 
        int row_begin = 0, colum_begin = 0, row_end = n - 1, colum_end = n - 1; // 核心控制变量：4个变量确定一个矩形
        int num = 1;
        while (row_begin <= row_end && colum_begin <= colum_end) {
            switch (direction) {
            case 0: {
                for (int i = colum_begin; i <= colum_end; i++)
                    matrix[row_begin][i] = num++;
                
                row_begin++;
                direction = 1;
            }
                break;
            case 1: {
                for (int i = row_begin; i <= row_end; i++)
                    matrix[i][colum_end] = num++;
                
                colum_end--;
                direction = 2;
            }
                break;
            case 2: {
                for (int i = colum_end; i >= colum_begin; i--)
                    matrix[row_end][i] = num++;

                row_end--;
                direction = 3;
            }
                break;
            case 3: {
                for (int i = row_end; i >= row_begin; i--)
                    matrix[i][colum_begin] = num++;
                
                colum_begin++;
                direction = 0;
            }
                break;                    
            }
        }

        return matrix;
    }
};

int main(int argc, char const *argv[])
{
    int n = 3;
    Solution *solution = new Solution();
    vector<vector<int>> result = solution->generateMatrix(n);
    for (int i = 0; i < result.size(); i++) {
        vector<int> item = result[i];
        for (int j = 0; j < item.size(); j++) {
            cout << item[j] << " ";
        }
        cout << endl;
    }
    return 0;
}