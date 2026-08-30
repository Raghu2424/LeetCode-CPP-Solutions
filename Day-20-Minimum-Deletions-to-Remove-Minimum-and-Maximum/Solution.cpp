#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        auto [mn, mx] = minmax_element(nums.begin(), nums.end());

        int a = min(mn - nums.begin(), mx - nums.begin());
        int b = max(mn - nums.begin(), mx - nums.begin());

        return min({
            b + 1,
            n - a,
            a + 1 + n - b
        });
    }
};
