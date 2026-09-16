#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007LL;

        // C(n + k - 1, 2k)
        int N = n + k - 1;
        int R = 2 * k;

        vector<long long> dp(R + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= N; i++) {
            for (int j = min(i, R); j >= 1; j--) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return (int)dp[R];
    }
};
