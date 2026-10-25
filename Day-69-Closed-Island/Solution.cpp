#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int r, int c, vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Out of bounds or water cell
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1) {
            return;
        }

        // Mark land as visited
        grid[r][c] = 1;

        // Traverse all 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Step 1: Eliminate land connected to the boundary
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
                    && grid[r][c] == 0) {
                    dfs(r, c, grid);
                }
            }
        }

        // Step 2: Count remaining closed islands
        int closedIslandsCount = 0;

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(r, c, grid);
                }
            }
        }

        return closedIslandsCount;
    }
};
