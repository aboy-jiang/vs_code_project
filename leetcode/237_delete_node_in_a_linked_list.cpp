/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-16
 * @brief https://leetcode-cn.com/problems/delete-node-in-a-linked-list/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // 复制node结点后面的一个结点
        node->next = node->next->next; // 删除node结点后面的一个结点
    }
};

int main(int argc, char const *argv[])
{
    ListNode *v_4 = new ListNode(4);
    ListNode *v_5 = new ListNode(5);
    ListNode *v_1 = new ListNode(1);
    ListNode *v_9 = new ListNode(9);
    v_4->next = v_5;
    v_5->next = v_1;
    v_1->next = v_9;

    ListNode *head = v_4, *result;

    Solution *solution = new Solution();
    solution->deleteNode(v_1);
    print_list(head);
}