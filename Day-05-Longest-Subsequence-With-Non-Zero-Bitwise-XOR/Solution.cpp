#include <vector>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xorAll = 0;
        bool hasNonZero = false;

        for (int num : nums) {
            xorAll ^= num;

            if (num != 0) {
                hasNonZero = true;
            }
        }

        // If total XOR is non-zero, the entire array is valid.
        if (xorAll != 0) {
            return nums.size();
        }

        // If XOR is zero and there is a non-zero element,
        // remove one element to make XOR non-zero.
        return hasNonZero ? nums.size() - 1 : 0;
    }
};
