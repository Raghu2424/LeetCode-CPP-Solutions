#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int totalSum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_set<int> distinctSet;

            for (int j = i; j < n; j++) {
                distinctSet.insert(nums[j]);
                int distinctCount = distinctSet.size();
                totalSum += distinctCount * distinctCount;
            }
        }

        return totalSum;
    }
};
