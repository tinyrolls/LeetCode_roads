#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
      string answer = "";
      int row = 0;
      while (row < numRows) {
        for (int i = row; i < s.length(); i += 2 * (numRows - 1)) {
          answer += s[i];
          if (numRows == 1) {
            i++;
          } else if (row != 0 && row != numRows - 1) {
            if (i + (numRows - row - 1) * 2 < s.length())
              answer += s[i + (numRows - row - 1) * 2];
          }
        }
        row++;
      }
      return answer;
    }
};

int main() {
    Solution s;
    string a = "ABCD";
    string b;
    b = s.convert(a, 2);
    cout << b << endl;
}
