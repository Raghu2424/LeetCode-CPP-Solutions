#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = INT_MAX;
        bool odd = false, even = false;

        for (int x : nums1) {
            mn = min(mn, x);
            if (x & 1) odd = true;
            else even = true;
        }

        if (!odd || !even)
            return true;

        return mn & 1;
    }
};
