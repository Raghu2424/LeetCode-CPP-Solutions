#include <string>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int end = -1;

        for (int i = 0; i < n; i++) {
            // Try palindrome of length k
            int l = i;
            int r = i + k - 1;

            if (r < n && l > end && isPalindrome(s, l, r)) {
                count++;
                end = r;
                continue;
            }

            // Try palindrome of length k + 1
            r = i + k;

            if (r < n && l > end && isPalindrome(s, l, r)) {
                count++;
                end = r;
            }
        }

        return count;
    }

private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};
