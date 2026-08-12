#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freq[nums[right]]++;

            // Shrink the window if frequency exceeds k
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
