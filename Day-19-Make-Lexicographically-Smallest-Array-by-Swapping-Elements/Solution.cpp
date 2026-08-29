#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int, int>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {nums[i], i};

        sort(a.begin(), a.end());

        vector<int> ans(n);

        for (int i = 0; i < n; ) {
            int j = i;

            while (j + 1 < n &&
                   a[j + 1].first - a[j].first <= limit)
                j++;

            vector<int> idx;

            for (int k = i; k <= j; k++)
                idx.push_back(a[k].second);

            sort(idx.begin(), idx.end());

            for (int k = 0; k < idx.size(); k++)
                ans[idx[k]] = a[i + k].first;

            i = j + 1;
        }

        return ans;
    }
};
