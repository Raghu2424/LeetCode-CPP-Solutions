#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> last(26, 0);

        long long total = 0;

        for (char c : s) {
            int i = c - 'a';
            long long add = (total + 1) % MOD;

            total = (total + add - last[i] + MOD) % MOD;
            last[i] = add;
        }

        return total;
    }
};
