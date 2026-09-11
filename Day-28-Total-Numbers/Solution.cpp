class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);
        for (int d : digits) freq[d]++;

        int count = 0;

        for (int num = 100; num <= 998; num += 2) {
            int a = num / 100;
            int b = (num / 10) % 10;
            int c = num % 10;

            vector<int> used(10);
            used[a]++;
            used[b]++;
            used[c]++;

            bool possible = true;
            for (int i = 0; i < 10; i++) {
                if (used[i] > freq[i]) {
                    possible = false;
                    break;
                }
            }

            if (possible) count++;
        }

        return count;
    }
};
