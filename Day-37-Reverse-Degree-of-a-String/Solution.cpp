#include <string>
using namespace std;

class Solution {
public:
    int reverseDegree(string s) {
        int total = 0;

        for (int i = 0; i < s.length(); ++i) {
            // Reverse alphabet position:
            // 'a' -> 26, 'b' -> 25, ..., 'z' -> 1
            int rev_alpha_pos = 26 - (s[i] - 'a');

            // 1-indexed position in the string
            int str_pos = i + 1;

            total += rev_alpha_pos * str_pos;
        }

        return total;
    }
};
