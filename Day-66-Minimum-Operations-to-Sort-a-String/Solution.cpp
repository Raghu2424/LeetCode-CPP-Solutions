#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        // 1. If already sorted, 0 operations
        if (std::is_sorted(s.begin(), s.end())) {
            return 0;
        }
        
        // 2. If length is 2 and unsorted, it's impossible (-1)
        if (n == 2) {
            return -1;
        }
        
        char mn = *std::min_element(s.begin(), s.end());
        char mx = *std::max_element(s.begin(), s.end());
        
        // 3. One operation condition:
        // Can be sorted in 1 op if the min is at index 0 or max is at index n-1
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // 4. Three operations condition:
        // Only if max is at index 0, min is at index n-1, 
        // AND the max appears only at index 0 and min appears only at index n-1.
        // For inputs like "jgg", 'g' appears multiple times, so it takes 2 operations instead.
        bool unique_mx_at_start = (s[0] == mx);
        for (int i = 1; i < n; ++i) {
            if (s[i] == mx) {
                unique_mx_at_start = false;
                break;
            }
        }
        
        bool unique_mn_at_end = (s[n - 1] == mn);
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == mn) {
                unique_mn_at_end = false;
                break;
            }
        }
        
        if (unique_mx_at_start && unique_mn_at_end) {
            return 3;
        }
        
        // 5. Otherwise -> 2 operations
        return 2;
    }
};
