#include <string>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int needed = 0;

        for (char c : s) {
            if (c == '(') {
                // Complete the previous "))" pair if needed is odd
                if (needed % 2 != 0) {
                    insertions++;
                    needed--;
                }

                needed += 2;
            } else {
                needed--;

                // Insert '(' if there is no matching opening parenthesis
                if (needed < 0) {
                    insertions++;
                    needed += 2;
                }
            }
        }

        return insertions + needed;
    }
};
