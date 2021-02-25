/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-02-25
 * @brief https://leetcode-cn.com/problems/merge-k-sorted-lists/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {        
        int k = lists.size();
        if (k == 0) return nullptr;

        ListNode *result = nullptr, *tail = nullptr, *p = nullptr;
        int min_row;
        while (1) {
            for (int i = 0; i < k; i++) {
                if (lists[i] == nullptr) continue;
                
                // 寻找最小值
                if (p == nullptr) {
                    p = lists[i];
                    min_row = i;
                }
                if (lists[i]->val < p->val) {
                    p = lists[i];
                    min_row = i;                    
                }
            }

            // 没有最小值，结束
            if (p == nullptr) break;

            if (result == nullptr) {
                result = p;
                tail = p;                
            } else {
                tail->next = p;
                tail = tail->next;
            }

            lists[min_row] = lists[min_row]->next;
            p = nullptr;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> l1_arr = {1, 4, 5}, l2_arr = {1, 3, 4}, l3_arr = {2, 6};
    ListNode *l1, *l2, *l3, *result;
    l1 = create_list(l1_arr);
    l2 = create_list(l2_arr);
    l3 = create_list(l3_arr);
    vector<ListNode *> lists = {l1, l2, l3};
    Solution *solution = new Solution();
    result = solution->mergeKLists(lists);
    print_list(result);
    return 0;
}