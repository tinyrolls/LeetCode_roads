#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int reverse(int number) {
      long int temp = 0;
      while(number != 0) {
        int unit = number % 10;
        number = number / 10;
        temp = temp*10 + unit;
        if (temp > INT_MAX || temp < INT_MIN) {
          return 0;
        }
      }
      return (int)temp;
    }
};

int main() {
    Solution s;
    int a = 0;                            ;
    int b;
    b = s.reverse(a);
    cout << b << endl;
}
