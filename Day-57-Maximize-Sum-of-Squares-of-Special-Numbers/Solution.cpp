#include <vector>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bitCount(32, 0);

        for (int x : nums) {
            for (int i = 0; i < 32; ++i) {
                if ((x >> i) & 1) {
                    bitCount[i]++;
                }
            }
        }

        long long totalSum = 0;
        const long long MOD = 1000000007LL;

        for (int step = 0; step < k; ++step) {
            long long currentNum = 0;

            for (int i = 0; i < 32; ++i) {
                if (bitCount[i] > 0) {
                    currentNum |= (1LL << i);
                    bitCount[i]--;
                }
            }

            totalSum = (totalSum + (currentNum * currentNum) % MOD) % MOD;
        }

        return static_cast<int>(totalSum);
    }
};
