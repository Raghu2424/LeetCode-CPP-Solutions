#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c[3] = {};

        for (int x : stones)
            c[x % 3]++;

        if (c[0] % 2 == 0)
            return c[1] && c[2];

        return abs(c[1] - c[2]) > 2;
    }
};
