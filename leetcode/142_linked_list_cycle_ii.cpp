/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-11
 * @brief https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            
            if (fast->next == nullptr) return nullptr; // 无环

            fast = fast->next->next;

            if (slow == fast) {
                ListNode *p = head;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }        
                return p;
            }
        }
        return nullptr;
    }
};
 

int main(int argc, char const *argv[])
{
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    Solution *solution = new Solution();
    ListNode *result = solution->detectCycle(node1);
    if(result != nullptr)
        cout << result->val << endl;
    return 0;
}