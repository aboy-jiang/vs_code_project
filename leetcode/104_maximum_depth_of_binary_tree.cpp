/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-08
 * @brief 
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *node_15 = new TreeNode(15);
    TreeNode *node_7 = new TreeNode(7); 
    TreeNode *node_20 = new TreeNode(20, node_15, node_7);
    TreeNode *node_9 = new TreeNode(9);
    TreeNode *node_3 = new TreeNode(3, node_9, node_20);
    Solution *solution = new Solution();
    cout << solution->maxDepth(node_3) << endl;

    return 0;
}