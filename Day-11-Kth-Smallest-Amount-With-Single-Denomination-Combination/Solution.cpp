#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
    long long lcm(long long a, long long b) {
        return a / gcd(a, b) * b;
    }

    long long count(long long x, vector<int>& coins) {
        int n = coins.size();
        long long ans = 0;

        for (int mask = 1; mask < (1 << n); mask++) {
            long long L = 1;
            int bits = 0;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    bits++;
                    L = lcm(L, coins[i]);

                    if (L > x) break;
                }
            }

            if (L <= x) {
                long long v = x / L;
                ans += (bits & 1) ? v : -v;
            }
        }

        return ans;
    }

public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = 1;
        long long hi = 1LL * *min_element(coins.begin(), coins.end()) * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (count(mid, coins) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        return lo;
    }
};
