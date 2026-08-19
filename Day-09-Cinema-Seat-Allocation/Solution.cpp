#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rows;

        for (auto& seat : reservedSeats) {
            int r = seat[0], c = seat[1];

            if (c >= 2 && c <= 9)
                rows[r] |= 1 << (c - 2);
        }

        int ans = (n - rows.size()) * 2;

        const int L = 15;   // Seats 2-5
        const int R = 240;  // Seats 6-9
        const int M = 60;   // Seats 4-7

        for (auto& [r, mask] : rows) {
            bool left = !(mask & L);
            bool right = !(mask & R);

            if (left && right)
                ans += 2;
            else if (left || right || !(mask & M))
                ans++;
        }

        return ans;
    }
};
