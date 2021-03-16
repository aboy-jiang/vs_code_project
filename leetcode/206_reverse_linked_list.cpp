/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-16
 * @brief https://leetcode-cn.com/problems/reverse-linked-list/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p = head, *p_pre = nullptr, *p_next = nullptr;
        while (p != nullptr) {
            p_next = p->next;
            p->next = p_pre;
            
            p_pre = p;
            p = p_next;
        }
        return p_pre;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *v_1 = new ListNode(1);
    ListNode *v_2 = new ListNode(2);
    ListNode *v_3 = new ListNode(3);
    ListNode *v_4 = new ListNode(4);
    ListNode *v_5 = new ListNode(5);
    v_1->next = v_2;
    v_2->next = v_3;
    v_3->next = v_4;
    v_4->next = v_5;

    ListNode *head = v_1, *result;

    Solution *solution = new Solution();
    result = solution->reverseList(head);
    print_list(result);
    return 0;
}