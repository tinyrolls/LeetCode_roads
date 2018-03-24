#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int L = nums1.size();
        return (L % 2 == 0 ? (nums1[L/2] + nums1[L/2-1])/2.0 : nums1[L/2]);
    }
};

int main() {
    Solution s;
    int n1[] = {1, 3, 2};
    int n2[] = {1, 2, 3, 4};
    vector<int> a1(n1, n1+2);
    vector<int> b1(n1+2, n1+3);
    vector<int> a2(n2, n2+2);
    vector<int> b2(n2+2, n2+4);


    double Result = s.findMedianSortedArrays(a1, b1);
    cout << Result << endl;
    Result = s.findMedianSortedArrays(a2, b2);
    cout << Result << endl;
}
