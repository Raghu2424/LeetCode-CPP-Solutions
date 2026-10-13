#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squaredNums(n);

        // Square each element
        for (int i = 0; i < n; i++) {
            long long val = nums[i];
            squaredNums[i] = val * val;
        }

        // Sort squared values in ascending order
        sort(squaredNums.begin(), squaredNums.end());

        long long totalScore = 0;
        int left = 0, right = n - 1;
        bool add = true;

        // Greedily maximize the alternating sum
        while (left <= right) {
            if (add) {
                totalScore += squaredNums[right];
                right--;
            } else {
                totalScore -= squaredNums[left];
                left++;
            }

            add = !add;
        }

        return totalScore;
    }
};
