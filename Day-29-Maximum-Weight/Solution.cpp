#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
    struct Interval {
        int l, r, weight, id;
    };

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<Interval> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i] = {intervals[i][0], intervals[i][1],
                      intervals[i][2], i};
        }

        sort(arr.begin(), arr.end(), [](const Interval& a,
                                        const Interval& b) {
            if (a.l != b.l) return a.l < b.l;
            if (a.r != b.r) return a.r < b.r;
            if (a.weight != b.weight) return a.weight > b.weight;
            return a.id < b.id;
        });

        vector<int> starts(n);
        for (int i = 0; i < n; i++)
            starts[i] = arr[i].l;

        using DP = pair<long long, vector<int>>;
        vector<vector<DP>> dp(n + 1, vector<DP>(5, {0, {}}));

        auto better = [](const DP& a, const DP& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            int next = upper_bound(
                starts.begin(), starts.end(), arr[i].r
            ) - starts.begin();

            for (int k = 1; k <= 4; k++) {
                DP best = dp[i + 1][k];

                DP take;
                take.first = arr[i].weight + dp[next][k - 1].first;
                take.second = {arr[i].id};

                take.second.insert(
                    take.second.end(),
                    dp[next][k - 1].second.begin(),
                    dp[next][k - 1].second.end()
                );

                sort(take.second.begin(), take.second.end());

                if (better(take, best))
                    best = take;

                dp[i][k] = best;
            }
        }

        DP ans = {0, {}};

        for (int k = 1; k <= 4; k++) {
            if (better(dp[0][k], ans))
                ans = dp[0][k];
        }

        return ans.second;
    }
};
