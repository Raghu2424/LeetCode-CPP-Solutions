#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long total_k = static_cast<long long>(k1) + k2;

        // Count frequencies of absolute differences
        vector<long long> count(100001, 0);
        long long max_diff = 0;

        for (int i = 0; i < n; ++i) {
            long long diff = abs(nums1[i] - nums2[i]);
            count[diff]++;
            max_diff = max(max_diff, diff);
        }

        // Greedily reduce the largest differences
        for (long long d = max_diff; d > 0 && total_k > 0; --d) {
            if (count[d] == 0) {
                continue;
            }

            long long take = min(total_k, count[d]);
            count[d] -= take;
            count[d - 1] += take;
            total_k -= take;
        }

        // Calculate the minimum sum of squared differences
        long long ans = 0;

        for (long long d = 1; d <= max_diff; ++d) {
            ans += count[d] * d * d;
        }

        return ans;
    }
};
