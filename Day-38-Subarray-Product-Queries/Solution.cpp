#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> nextDp(k, 0);
            int val = num % k;

            // Single-element subarray
            nextDp[val]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int nextRem = (r * val) % k;
                    nextDp[nextRem] += dp[r];
                }
            }

            // Add current subarray counts
            for (int r = 0; r < k; r++) {
                result[r] += nextDp[r];
            }

            dp = move(nextDp);
        }

        return result;
    }
};
