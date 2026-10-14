#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num || sum < 0) {
            return "";
        }

        string result = "";

        for (int i = 0; i < num; ++i) {
            int cur = min(9, sum);
            result += to_string(cur);
            sum -= cur;
        }

        return result;
    }
};
