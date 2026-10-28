```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(1024, false))
        );

        // Base case: start cell (0, 0)
        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int xorVal = 0; xorVal < 1024; xorVal++) {
                    if (!dp[i][j][xorVal]) {
                        continue;
                    }

                    // Move right
                    if (j + 1 < n) {
                        dp[i][j + 1][xorVal ^ grid[i][j + 1]] = true;
                    }

                    // Move down
                    if (i + 1 < m) {
                        dp[i + 1][j][xorVal ^ grid[i + 1][j]] = true;
                    }
                }
            }
        }

        // Find the minimum reachable XOR value
        for (int xorVal = 0; xorVal < 1024; xorVal++) {
            if (dp[m - 1][n - 1][xorVal]) {
                return xorVal;
            }
        }

        return 0;
    }
};
```
