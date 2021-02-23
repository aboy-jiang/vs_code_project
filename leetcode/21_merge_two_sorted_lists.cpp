/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-23
 * @brief https://leetcode-cn.com/problems/merge-two-sorted-lists/
 * 
 * 解决思路：
 * 双指针，逐个遍历比较
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
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
    vector<int> l1_arr = {1, 2, 4}, l2_arr = {1, 3, 4};
    ListNode *l1, *l2, *result;
    l1 = create_list(l1_arr);
    l2 = create_list(l2_arr);
    Solution *solution = new Solution();
    result = solution->mergeTwoLists(l1, l2);
    print_list(result);
    return 0;
}

