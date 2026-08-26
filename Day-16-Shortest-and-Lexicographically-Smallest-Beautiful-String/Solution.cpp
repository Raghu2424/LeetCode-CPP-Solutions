#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0, ones = 0, minLen = INT_MAX;
        string ans = "";

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1')
                ones++;

            while (ones == k) {
                while (left < right && s[left] == '0')
                    left++;

                string cur = s.substr(left, right - left + 1);

                if (cur.size() < minLen ||
                    (cur.size() == minLen && cur < ans)) {
                    minLen = cur.size();
                    ans = cur;
                }

                if (s[left] == '1')
                    ones--;

                left++;
            }
        }

        return ans;
    }
};
