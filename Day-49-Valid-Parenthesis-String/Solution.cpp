#include <string>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            } else if (c == ')') {
                minOpen--;
                maxOpen--;
            } else {
                // '*' can be treated as ')', '(' or empty
                minOpen--;
                maxOpen++;
            }

            if (maxOpen < 0) {
                return false;
            }

            if (minOpen < 0) {
                minOpen = 0;
            }
        }

        return minOpen == 0;
    }
};
