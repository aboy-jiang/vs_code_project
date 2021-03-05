/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-04
 * @brief https://leetcode-cn.com/problems/rotate-list/
 * 
 * 解决思路：
 * 1、将链表修改成循环链表，并记录长度n（用于计算最终断开位置）
 * 2、移动指针位置到断开位置，断开循环链表，并返回新链表
 * 
 * 1到5循环链表断开位置计算公式：
 * 设p指向断开位置右侧元素，初始值指向1
 * 移动位置k：         0   1   2   3   4  
 * p指向元素：         5   4   3   2   1   
 * p指移动步长step：   4   3   2   1   0 
 * 因此k和step的关系：step = (n-1) - k % n
 */

#include <iostream>
#include <vector>
#include "structure"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) return head;
    
        ListNode *p = head;
        int n = 0;
        while (p->next != nullptr) { // 这里是移动到了最后一个，因此循环结束n还需在+1
            p = p->next;
            n++;
        }
        n++;
        p->next = head;
        
        int step = (n-1) - k % n;
        p = head;
        while (step > 0){
            p = p->next;
            step--;
        } 
        head = p->next;
        p->next = nullptr;

        return head;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> list_arr = {1, 2, 3, 4, 5};
    ListNode *list = create_list(list_arr);
    Solution *solution = new Solution();
    ListNode *p = solution->rotateRight(list, 2);
    while (p != nullptr) {
        cout << p->val << endl;
        p = p->next;
    }
    
    return 0;
}