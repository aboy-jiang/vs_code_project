/**
 * @author JZC (aboy.jiang@aliyun.com)
 * @date 2021-03-11
 * @brief https://leetcode-cn.com/problems/min-stack/
 * 
 * 解决思路：
 */

#include <iostream>
#include <vector>
using namespace std;

class MinStack {
public:
    vector<int> stack;
    int min_value, len;
    /** initialize your data structure here. */
    MinStack() {
        min_value = INT_MAX;
        len = 0;
    }
    
    void push(int x) {
        stack.push_back(x);
        len++;
        
        min_value = min(min_value, x);
    }
    
    void pop() {
        if (len == 0) return;

        int top_value = top();
        stack.pop_back();
        len--;

        if (top_value <= min_value) {
            min_value = INT_MAX;
            for (auto i : stack) {
                min_value = min(min_value, i);
            }
        }
    }
    
    int top() {
        return stack[len-1];
    }
    
    int getMin() {
        return min_value;
    }
};

int main(int argc, char const *argv[])
{
    int min1, top, min2;
    MinStack *minStack = new MinStack();
    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    min1 = minStack->getMin(); // 返回 -3
    minStack->pop();
    top = minStack->top(); // 返回 0
    min2 = minStack->getMin(); // 返回 -2
    cout << min1 << " " << top << " " << min2;
    return 0;
}