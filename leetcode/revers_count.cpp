#include <iostream>
#include <vector>

using namespace std;

// 排序+逆序数：在排序时，同时计算和打印逆序数。
int sort_and_count(vector<int>& array, int left, int mid, int right) {
    int count = 0, i, j, k; // count逆序数对数，i左侧数组角标，j右侧数组角标，k为temp数组角标
    vector<int> temp = array; // 存储排序后的数组
    for (i = left, j = mid + 1, k = left; i <= mid && j <= right; ++k) { // 遍历左右子数组
        if (array[i] <= array[j]) { // 如果左侧的数据较小，则取左侧数据放入排序后的数组temp中
            temp[k] = array[i];
            i++;
        } else {  // 如果右侧的数据较小，则取右侧数据放入排序后的数组temp中。并且此时需要计算逆序数
            temp[k] = array[j];
            
            // 累加逆序数对数
            count += (mid - i + 1);
            // 打印逆序数
            for (int l = i; l <= mid; l++) {
                cout << "[" << array[l] << "," << array[j] << "]" << endl;
            }

            j++;
        }
    }
    
    while (i <= mid) temp[k++] = array[i++];
    while (j <= right) temp[k++] = array[j++];
    
    array = temp;
    
    return count;
}

int merage_and_count(vector<int>& array, int left, int right) {
    if (right - left <= 0) return 0; // 递归出口：拆分到只有一个元素
    int mid = (left + right) / 2; // 数组中位数，用于拆分数组
    int l_count = merage_and_count(array, left, mid); // 递归：左侧子数组
    int r_count = merage_and_count(array, mid+1, right); // 递归：右侧子数组
    int s_count = sort_and_count(array, left, mid, right); // 排序并计算和打印逆序数对数
    return l_count + r_count + s_count; 
}

int revers_count(vector<int>& array) {
	return merage_and_count(array, 0, array.size() - 1);
}

int main() {
    vector<int> A = {11, 0, -14, -7, 17, -2, 16, 22};
    int count = revers_count(A);
    cout << "revers_count："  << count;
    return 0;
}