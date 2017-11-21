#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = s.length();
        int max_length = 0;
        int* Value = new int[L];
        memset(Value, 0, L*sizeof(int));
        for (int i = 0; i < L; i++) {
            int count = 1;
            for (int j = 0; j < Value[i-1]; j++) {
                if (s[i] != s[i-1-j]) count++;
                else break;
            }
            Value[i] = count;
            max_length = (count > max_length ? count : max_length);
        }
        return max_length;
    }
};

int main() {
    Solution s1;
    string a = "pwwkew";
    int Result = s1.lengthOfLongestSubstring(a);
    cout << Result << endl;
}
