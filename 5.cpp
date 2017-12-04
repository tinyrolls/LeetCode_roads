#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int max = 0;
        int number = 0;
        int changdu = 0;
        int j = 0;
        for (int i = 0; i < s.length(); i++) {
            changdu = 0; j=0;
            while(i-1-j >= 0 && s[i-1-j] == s[i+j] && i+j<s.length()) {
                changdu += 2;
                j++;
            }
            if (changdu > max) {
                max = changdu;
                number = i;
            }
            changdu = 1;
            j = 1;
            while(i-j >= 0 && s[i-j] == s[i+j] && i+j < s.length()) {
                changdu += 2;
                j++;
            }
            if (changdu > max) {
                max = changdu;
                number = i;
            }
            // cout << s[i] << " max:" << max << " number:" << number<<endl;
        }
        result.assign(s, number-max/2, max);
        return  result;
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
