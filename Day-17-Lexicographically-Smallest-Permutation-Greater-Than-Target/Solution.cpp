#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26);

        for (char c : s)
            cnt[c - 'a']++;

        for (int i = 0; i < n; i++) {
            int x = target[i] - 'a';

            if (cnt[x] > 0) {
                cnt[x]--;
                continue;
            }

            for (int c = x + 1; c < 26; c++) {
                if (cnt[c] == 0) continue;

                string ans = target.substr(0, i);
                ans += char('a' + c);
                cnt[c]--;

                for (int j = 0; j < 26; j++)
                    ans.append(cnt[j], char('a' + j));

                return ans;
            }

            // Backtrack
            for (int j = i - 1; j >= 0; j--) {
                cnt[target[j] - 'a']++;

                for (int c = target[j] - 'a' + 1; c < 26; c++) {
                    if (cnt[c] == 0) continue;

                    string ans = target.substr(0, j);
                    ans += char('a' + c);
                    cnt[c]--;

                    for (int x2 = 0; x2 < 26; x2++)
                        ans.append(cnt[x2], char('a' + x2));

                    return ans;
                }
            }

            return "";
        }

        return "";
    }
};
