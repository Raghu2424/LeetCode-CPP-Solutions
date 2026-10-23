#include <vector>
using namespace std;

class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int max_k = -1;

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i) {
                if (max_k == -1) {
                    max_k = nums[i];
                } else {
                    max_k &= nums[i];
                }
            }
        }

        return (max_k == -1) ? 0 : max_k;
    }
};
