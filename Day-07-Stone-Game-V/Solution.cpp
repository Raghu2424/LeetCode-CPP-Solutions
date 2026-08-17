#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
    int dp[501][501], pre[501];

    int solve(int l, int r) {
        if (l == r) return 0;
        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;

        for (int k = l; k < r; k++) {
            int left = pre[k + 1] - pre[l];
            int right = pre[r + 1] - pre[k + 1];

            if (left < right)
                ans = max(ans, left + solve(l, k));
            else if (right < left)
                ans = max(ans, right + solve(k + 1, r));
            else
                ans = max(ans, left + max(solve(l, k), solve(k + 1, r)));
        }

        return dp[l][r] = ans;
    }

public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();

        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + stoneValue[i];

        return solve(0, n - 1);
    }
};
