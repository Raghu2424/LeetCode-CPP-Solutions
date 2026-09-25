#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> resultSet = parseExpr(expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }

private:
    set<string> parseExpr(const string& S) {
        set<string> resultSet;
        vector<set<string>> concatGroups;

        int n = S.length();
        int i = 0;

        while (i < n) {
            char c = S[i];

            if (c == '{') {
                int open = 1;
                int j = i + 1;

                while (j < n && open > 0) {
                    if (S[j] == '{')
                        open++;
                    else if (S[j] == '}')
                        open--;
                    j++;
                }

                set<string> inner =
                    parseExpr(S.substr(i + 1, j - i - 2));

                concatGroups.push_back(inner);
                i = j;

            } else if (isalpha(c)) {
                concatGroups.push_back({string(1, c)});
                i++;

            } else if (c == ',') {
                set<string> product =
                    combineCartesianProduct(concatGroups);

                resultSet.insert(product.begin(), product.end());
                concatGroups.clear();
                i++;
            }
        }

        set<string> product =
            combineCartesianProduct(concatGroups);

        resultSet.insert(product.begin(), product.end());

        return resultSet;
    }

    set<string> combineCartesianProduct(
        const vector<set<string>>& groups) {

        if (groups.empty())
            return {};

        set<string> current = {""};

        for (const auto& group : groups) {
            set<string> next;

            for (const string& prefix : current) {
                for (const string& suffix : group) {
                    next.insert(prefix + suffix);
                }
            }

            current = std::move(next);
        }

        return current;
    }
};
