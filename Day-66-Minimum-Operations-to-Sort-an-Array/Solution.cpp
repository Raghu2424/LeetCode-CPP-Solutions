#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int incIndex = -1;
        int decIndex = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) incIndex = i;
            if (nums[i] == n - 1) decIndex = i;
        }

        bool increasing = (incIndex != -1);
        bool decreasing = (decIndex != -1);

        for (int i = 0; i < n; i++) {
            if (increasing && nums[(incIndex + i) % n] != i) {
                increasing = false;
            }

            if (decreasing && nums[(decIndex + i) % n] != n - 1 - i) {
                decreasing = false;
            }

            if (!increasing && !decreasing) return -1;
        }

        int minOps = INT_MAX;

        if (increasing) {
            minOps = min(minOps, incIndex);
            minOps = min(minOps, 2 + (n - incIndex) % n);
        }

        if (decreasing) {
            minOps = min(minOps, 1 + (n - decIndex) % n);
            minOps = min(minOps, 1 + decIndex);
        }

        return minOps == INT_MAX ? -1 : minOps;
    }
};
