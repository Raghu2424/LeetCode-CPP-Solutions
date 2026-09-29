#include <vector>
#include <cstring>

using namespace std;

class Solution {
private:
    int memo[100][100][101];
    int m, n;

    bool dfs(vector<vector<char>>& grid, int r, int c, int open) {
        if (grid[r][c] == '(') {
            open++;
        } else {
            open--;
        }

        if (open < 0) {
            return false;
        }

        int remaining = (m - r - 1) + (n - c - 1);

        if (open > remaining) {
            return false;
        }

        if (r == m - 1 && c == n - 1) {
            return open == 0;
        }

        if (memo[r][c][open] != -1) {
            return memo[r][c][open];
        }

        bool found = false;

        if (r + 1 < m) {
            found = dfs(grid, r + 1, c, open);
        }

        if (!found && c + 1 < n) {
            found = dfs(grid, r, c + 1, open);
        }

        return memo[r][c][open] = found;
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int pathLength = m + n - 1;

        if (pathLength % 2 != 0) {
            return false;
        }

        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        memset(memo, -1, sizeof(memo));

        return dfs(grid, 0, 0, 0);
    }
};
