/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-16
 * @brief https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA, *pB = headB;

        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *v_0 = new ListNode(0);
    ListNode *v_9 = new ListNode(9);
    ListNode *v_1 = new ListNode(1);
    ListNode *v_2 = new ListNode(2);
    ListNode *v_4 = new ListNode(4);
    ListNode *v_3 = new ListNode(3);

    v_0->next = v_9;
    v_9->next = v_1;
    v_1->next = v_2;
    v_2->next = v_4; 
    // v_3->next = v_2;

    ListNode *headA = v_0, *headB = v_3; 

    // ListNode *v_3 = new ListNode(3);
    // ListNode *v_2 = new ListNode(2);
    // v_2->next = v_3;
    // ListNode *headA = v_3, *headB = v_2;

    Solution *solution = new Solution();
    ListNode *result = solution->getIntersectionNode(headA, headB);
    if (result != nullptr)
        cout << result->val << endl;
    return 0;
}