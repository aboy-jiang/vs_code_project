/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-10
 * @brief https://leetcode-cn.com/problems/linked-list-cycle/
 * 
 * 解决思路：
 * 快慢指针：每一次循环快指针都往前追1步，如果追到slow证明有环
 * 
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;

        ListNode *slow = head, *fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return true;
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
    cout << solution->hasCycle(node1) << endl;
    return 0;
}