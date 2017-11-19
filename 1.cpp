#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int NumbertoFind = target - nums[i];
            if (hash.find(NumbertoFind) != hash.end()) {
                result.push_back(hash[NumbertoFind]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};

int main() {
    Solution s1;
    int target = 9;
    int n[] = {2, 7, 11 ,15};
    vector<int> a(n, n+4);
    vector<int> result = s1.twoSum(a, target);

    vector<int>::iterator t ;
    for(t=result.begin(); t!=result.end(); t++)
        cout<<*t<<" " ;
}

/*
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/
