/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-01-19
 * @brief https://leetcode.com/problems/add-two-numbers/
 * 
 * 解决思路：
 * 遍历列表，逐个相加（进位值额外存储一个变量里）
 * 求余10（%10）=> 个位值（结点val值）
 * 整除10（/10）=> 十位值（下一个结点相加时候使用）
 * 
 * 总结：
 * 关键点在于线性表的操作
 * 指针默认初始化不是nullptr，需显示赋值
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carrying = 0; // 加法进位
        ListNode *list = nullptr, *p;  
        while (l1 != nullptr || l2 != nullptr) {
            int v1 = getValueAndMoveNext(l1);
            int v2 = getValueAndMoveNext(l2);
            int adding = carrying + v1 + v2;
            int node_val = adding % 10;
            carrying = adding / 10;

            ListNode *node = new ListNode(node_val);
            if(list == nullptr) {
                list = node;
                p = node;
            } else {
                p->next = node;
                p = node;
            }
        } 
 
        if (carrying > 0) {
            ListNode *node = new ListNode(carrying);
            p->next = node;
            p = node;          
        }

        return list;
    }
private:
    int getValueAndMoveNext(ListNode* &p) {
        int val = 0;
        if (p != nullptr) {
            val = p->val;
            p = p->next;
        }
        return val;
    }
};

ListNode* create_list(vector<int> arr) {
    ListNode *list = nullptr, *p;
    for (auto &&i : arr) {
        ListNode *node = new ListNode(i);
        if(list == nullptr) {
            list = node;
            p = node;
        } else {
            p->next = node;
            p = node;
        }
    }
    
    return list;
}

void print_list(ListNode *p) {
    while (p != nullptr) {
        cout << p->val << ' ';
        p = p->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> l1_arr = {9,9,9,9,9,9,9}, l2_arr = {9,9,9,9};
    ListNode *l1, *l2, *result;
    l1 = create_list(l1_arr);
    l2 = create_list(l2_arr);
    print_list(l1);
    print_list(l2);

    Solution *solution = new Solution();
    result = solution->addTwoNumbers(l1, l2);
    print_list(result);

    return 0;
}