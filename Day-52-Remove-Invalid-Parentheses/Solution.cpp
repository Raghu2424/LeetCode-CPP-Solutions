#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int leftRem = 0, rightRem = 0;

        for (char c : s) {
            if (c == '(') {
                leftRem++;
            } else if (c == ')') {
                if (leftRem > 0) {
                    leftRem--;
                } else {
                    rightRem++;
                }
            }
        }

        unordered_set<string> result;
        string current;

        backtrack(s, 0, 0, 0, leftRem, rightRem, current, result);

        return vector<string>(result.begin(), result.end());
    }

private:
    void backtrack(const string& s, int index, int leftCount,
                   int rightCount, int leftRem, int rightRem,
                   string& current, unordered_set<string>& result) {
        if (index == s.length()) {
            if (leftRem == 0 && rightRem == 0) {
                result.insert(current);
            }
            return;
        }

        char c = s[index];

        // Option 1: Remove the current parenthesis
        if (c == '(' && leftRem > 0) {
            backtrack(s, index + 1, leftCount, rightCount,
                      leftRem - 1, rightRem, current, result);
        } else if (c == ')' && rightRem > 0) {
            backtrack(s, index + 1, leftCount, rightCount,
                      leftRem, rightRem - 1, current, result);
        }

        // Option 2: Keep the current character
        current.push_back(c);

        if (c != '(' && c != ')') {
            backtrack(s, index + 1, leftCount, rightCount,
                      leftRem, rightRem, current, result);
        } else if (c == '(') {
            backtrack(s, index + 1, leftCount + 1, rightCount,
                      leftRem, rightRem, current, result);
        } else if (leftCount > rightCount) {
            backtrack(s, index + 1, leftCount, rightCount + 1,
                      leftRem, rightRem, current, result);
        }

        current.pop_back();
    }
};
