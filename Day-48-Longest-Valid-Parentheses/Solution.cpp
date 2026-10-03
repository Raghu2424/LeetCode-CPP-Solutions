#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;
        int n = s.length();

        // Left-to-Right Pass
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }

        left = right = 0;

        // Right-to-Left Pass
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right) {
                maxLen = max(maxLen, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }

        return maxLen;
    }
};
