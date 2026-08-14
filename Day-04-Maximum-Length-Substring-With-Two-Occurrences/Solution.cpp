#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> count(26, 0);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            count[s[right] - 'a']++;

            // Shrink the window if a character appears more than twice
            while (count[s[right] - 'a'] > 2) {
                count[s[left] - 'a']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
