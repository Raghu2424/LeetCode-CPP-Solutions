class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sum = 0, q = 0;

        for (int i = 0; i < n; i++) {
            if (num[i] == '?') {
                q += (i < n / 2 ? 1 : -1);
            } else {
                sum += (i < n / 2 ? 1 : -1) * (num[i] - '0');
            }
        }

        return sum * 2 + q * 9 != 0;
    }
};
