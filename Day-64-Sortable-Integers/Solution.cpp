#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    bool isCyclicRotation(const vector<int>& a,
                          const vector<int>& b,
                          int start,
                          int k) {
        vector<int> pattern(b.begin() + start, b.begin() + start + k);
        vector<int> lps(k, 0);

        for (int i = 1, len = 0; i < k;) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int matched = 0;

        for (int i = 0; i < 2 * k - 1; ++i) {
            int value = a[start + (i % k)];

            while (matched > 0 && value != pattern[matched]) {
                matched = lps[matched - 1];
            }

            if (value == pattern[matched]) {
                ++matched;
            }

            if (matched == k) {
                return true;
            }
        }

        return false;
    }

public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        long long totalSum = 0;

        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;

            bool isSortable = true;

            for (int i = 0; i < n; i += k) {
                if (!isCyclicRotation(nums, sortedNums, i, k)) {
                    isSortable = false;
                    break;
                }
            }

            if (isSortable) {
                totalSum += k;
            }
        }

        return static_cast<int>(totalSum);
    }
};
