/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-11
 * @brief https://leetcode-cn.com/problems/sort-list/
 * 
 * 解决思路：
 * 归并排序
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head; // 递归出口

        // 链表长度
        ListNode *p = head, *q;
        int len = 0;
        while (p != nullptr) {
            p = p->next;
            len++;
        }
        
        // 定位链表中间位置，并切断链表
        p = head;
        for (int i = 0; i < len/2; i++) {
            q = p;
            p = p->next;
        }
        q->next = nullptr;

        // 左右链表排序
        ListNode *left = sortList(head), *right = sortList(p);

        // 合并左右排序后的链表
        return mergeTwoLists(left, right);
    }
    

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *list = nullptr, *list_tail = nullptr, *p;    
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p = l1; 
                l1 = l1->next;
            } else {
                p = l2;
                l2 = l2->next;    
            }
            
            if(list == nullptr) { // 初始化list
                list = p;
            } else {
                list_tail->next = p;
            }
            list_tail = p;
        }

        // 将未遍历完的l1或l2添加到list最后面
        p = l1 != nullptr ? l1 : l2;
        if(list == nullptr) { // 初始化list
            list = p;
        } else {
            list_tail->next = p;
        }
        
        return list;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *node1 = new ListNode(-1);
    ListNode *node2 = new ListNode(5);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(0);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;  
    node4->next = node5;
     
    Solution *solution = new Solution();
    ListNode *result = solution->sortList(node1);
    print_list(result);    
    return 0;
}