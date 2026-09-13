#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<unsigned int> bits1(n, 0);
        vector<unsigned int> bits2(n, 0);

        // Convert each row into a bitmask
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j])
                    bits1[i] |= (1U << j);

                if (img2[i][j])
                    bits2[i] |= (1U << j);
            }
        }

        int maxOverlap = 0;

        // Try every possible vertical shift
        for (int dy = -(n - 1); dy <= n - 1; dy++) {

            // Try every possible horizontal shift
            for (int dx = -(n - 1); dx <= n - 1; dx++) {

                int overlap = 0;

                for (int i = 0; i < n; i++) {
                    int j = i + dy;

                    if (j < 0 || j >= n)
                        continue;

                    unsigned int shifted;

                    if (dx >= 0)
                        shifted = bits2[j] << dx;
                    else
                        shifted = bits2[j] >> (-dx);

                    overlap += __builtin_popcount( bits1[i] & shifted );
                }

                maxOverlap = max(maxOverlap, overlap);
            }
        }

        return maxOverlap;
    }
};
