#include <iostream>
#include <vector>
using namespace std;

void print_LCS(vector<vector<string>> p, string x, int i, int j) {
    if (i == 0 || j == 0) {
        return;
    }
    if (p[i][j] == "LU") {
        print_LCS(p, x, i-1, j-1);
        cout << x[i-1];
    } else if (p[i][j] == "U") {
        print_LCS(p, x, i-1, j);
    } else {
        print_LCS(p, x, i, j-1);
    }
}

void longest_common_subsquence(string x, string y) {
    int m = x.length() + 1; // 二维数组长度，在字符串长度基础上+1
    int n = y.length() + 1;
    vector<vector<int>> d(m ,vector<int>(n)); // 使用c++的vector定义二维数组
    vector<vector<string>> p(m ,vector<string>(n)); 
    for (int i = 0; i < m; i++) { // 初始化二维数组
        d[i][0] = 0;
        p[i][0] = "*";
    }
    for (int j = 0; j < n; j++) {
        d[0][j] = 0;
        p[0][j] = "*";
    }
    
    for (int i = 1; i < m; i++) { // 从左到右，从上到下遍历二维数组
        for (int j = 1; j < n; j++) { 
            if (x[i-1] == y[j-1]) { // 递归式第一种情况
                d[i][j] = d[i-1][j-1] + 1;
                p[i][j] = "LU";
            } else if (d[i-1][j] >= d[i][j-1]){ // 递归式第二种情况1
                d[i][j] = d[i-1][j];
                p[i][j] = "U";
            } else {  // 递归式第二种情况2
                d[i][j] = d[i][j-1];
                p[i][j] = "L";
            }
        }
    }

    cout << "d[i,j]\n";
    for (int i = 0; i < m; i++) { // 输出d[i,j]
        for (int j = 0; j < n; j++) { 
            cout << d[i][j] << "\t";                
        }
        cout << "\n";
    }
    cout << "p[i,j]\n";
    for (int i = 0; i < m; i++) { // 输出p[i,j]
        for (int j = 0; j < n; j++) { 
            cout << p[i][j] << "\t";                
        }
        cout << "\n";
    }
    
    cout << "LCS = ";
    print_LCS(p, x, m-1, n-1); // 输出LCS
}

int main() {
    string x = "XYXZYXY";
    string y = "XZYZZYX";
    longest_common_subsquence(x, y);
    return 0;
}