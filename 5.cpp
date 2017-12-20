#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //优秀方法
        if (s.empty()) return "";               //异常判断
        if (s.size() == 1) return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {        //从前遍历
          if (s.size() - i <= max_len / 2) break;   //跳过后期太短的不可能部分
          int j = i, k = i;
          while (k < s.size()-1 && s[k+1] == s[k]) ++k; // 连续相同必然对称，先直接数过去
          i = k+1;  //新的端点是之前的i和后来的k+1
          while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // 不相同字母延展
          int new_len = k - j + 1;  //长度
          if (new_len > max_len) { min_start = j; max_len = new_len; } //置MAX
        }
        return s.substr(min_start, max_len);
    }
};

int main() {
    Solution s;
    string a = "babad";
    string b = "aaaa";
    string c, d;
    c = s.longestPalindrome(a);
    cout << c << endl;
    d = s.longestPalindrome(b);
    cout << d << endl;
}
