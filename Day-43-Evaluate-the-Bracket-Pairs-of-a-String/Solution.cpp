#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        for (const auto& pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string result = "";
        string currentKey = "";
        bool insideBracket = false;

        for (char c : s) {
            if (c == '(') {
                insideBracket = true;
                currentKey = "";
            } 
            else if (c == ')') {
                insideBracket = false;

                if (mp.count(currentKey)) {
                    result += mp[currentKey];
                } else {
                    result += '?';
                }
            } 
            else {
                if (insideBracket) {
                    currentKey += c;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};
