#include <vector>
using namespace std;

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();
        int validIslands = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    long long islandSum = dfs(grid, i, j, m, n);

                    if (islandSum % k == 0) {
                        validIslands++;
                    }
                }
            }
        }

        return validIslands;
    }

private:
    long long dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return 0;
        }

        long long currentVal = grid[r][c];
        grid[r][c] = 0; // Mark as visited

        currentVal += dfs(grid, r + 1, c, m, n);
        currentVal += dfs(grid, r - 1, c, m, n);
        currentVal += dfs(grid, r, c + 1, m, n);
        currentVal += dfs(grid, r, c - 1, m, n);

        return currentVal;
    }
};
