#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int h = n / 2;

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                if (mid != 0)
                    return "";
                mid = char('a' + i);
            }
            cnt[i] /= 2;
        }

        auto build = [&](const string& left) {
            string ans = left;

            if (mid != 0)
                ans += mid;

            for (int i = h - 1; i >= 0; i--)
                ans += left[i];

            return ans;
        };

        // Try matching target's first half
        {
            vector<int> rem = cnt;
            string left;
            bool ok = true;

            for (int i = 0; i < h; i++) {
                int x = target[i] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
                left += target[i];
            }

            if (ok) {
                string ans = build(left);

                if (ans > target)
                    return ans;
            }
        }

        // Change one position to a larger character
        for (int pos = h - 1; pos >= 0; pos--) {
            vector<int> rem = cnt;
            string prefix;
            bool ok = true;

            for (int i = 0; i < pos; i++) {
                int x = target[i] - 'a';

                if (rem[x] == 0) {
                    ok = false;
                    break;
                }

                rem[x]--;
                prefix += target[i];
            }

            if (!ok)
                continue;

            int current = target[pos] - 'a';

            for (int c = current + 1; c < 26; c++) {
                if (rem[c] == 0)
                    continue;

                string left = prefix + char('a' + c);
                rem[c]--;

                for (int x = 0; x < 26; x++) {
                    while (rem[x] > 0) {
                        left += char('a' + x);
                        rem[x]--;
                    }
                }

                return build(left);
            }
        }

        return "";
    }
};
