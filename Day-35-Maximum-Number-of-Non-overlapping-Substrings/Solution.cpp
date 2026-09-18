#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();

        vector<int> left(26, INT_MAX);
        vector<int> right(26, -1);

        // Find first and last occurrence of each character
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            left[c] = min(left[c], i);
            right[c] = i;
        }

        vector<pair<int, int>> intervals;

        // Find valid minimal intervals
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            if (i != left[c])
                continue;

            int r = right[c];
            bool valid = true;

            for (int j = i; j <= r; j++) {
                int x = s[j] - 'a';

                if (left[x] < i) {
                    valid = false;
                    break;
                }

                r = max(r, right[x]);
            }

            if (valid)
                intervals.push_back({i, r});
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](const pair<int, int>& a,
                const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<string> result;
        int lastEnd = -1;

        // Greedily choose non-overlapping intervals
        for (auto& interval : intervals) {
            int l = interval.first;
            int r = interval.second;

            if (l > lastEnd) {
                result.push_back(s.substr(l, r - l + 1));
                lastEnd = r;
            }
        }

        return result;
    }
};
