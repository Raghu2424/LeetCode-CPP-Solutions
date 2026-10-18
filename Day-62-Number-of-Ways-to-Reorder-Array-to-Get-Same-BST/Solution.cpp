#include <vector>
using namespace std;

class Solution {
private:
    static const int MOD = 1000000007;
    vector<vector<long long>> comb;

    long long dfs(const vector<int>& arr) {
        int n = arr.size();

        if (n <= 2) {
            return 1;
        }

        vector<int> left, right;
        int root = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] < root) {
                left.push_back(arr[i]);
            } else {
                right.push_back(arr[i]);
            }
        }

        long long waysLeft = dfs(left);
        long long waysRight = dfs(right);

        long long merges =
            comb[left.size() + right.size()][left.size()];

        return (((merges * waysLeft) % MOD) * waysRight) % MOD;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        comb.assign(n + 1, vector<long long>(n + 1, 0));

        for (int i = 0; i <= n; i++) {
            comb[i][0] = 1;

            for (int j = 1; j <= i; j++) {
                comb[i][j] =
                    (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
            }
        }

        return (dfs(nums) - 1 + MOD) % MOD;
    }
};
