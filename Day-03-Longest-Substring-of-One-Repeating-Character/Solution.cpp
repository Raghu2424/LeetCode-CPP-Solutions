#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
    struct Node {
        char leftChar = 0;
        char rightChar = 0;
        int prefixLen = 0;
        int suffixLen = 0;
        int maxLen = 0;
    };

    vector<Node> tree;

    Node merge(const Node& left, const Node& right,
               int leftSize, int rightSize) {
        Node res;

        res.leftChar = left.leftChar;
        res.rightChar = right.rightChar;

        res.maxLen = max(left.maxLen, right.maxLen);

        // Combine repeating characters across the boundary
        if (left.rightChar == right.leftChar) {
            res.maxLen = max(
                res.maxLen,
                left.suffixLen + right.prefixLen
            );
        }

        // Calculate prefix length
        res.prefixLen = left.prefixLen;

        if (left.prefixLen == leftSize &&
            left.rightChar == right.leftChar) {
            res.prefixLen = leftSize + right.prefixLen;
        }

        // Calculate suffix length
        res.suffixLen = right.suffixLen;

        if (right.suffixLen == rightSize &&
            left.rightChar == right.leftChar) {
            res.suffixLen = rightSize + left.suffixLen;
        }

        return res;
    }

    void build(const string& s, int node, int start, int end) {
        if (start == end) {
            tree[node].leftChar = s[start];
            tree[node].rightChar = s[start];
            tree[node].prefixLen = 1;
            tree[node].suffixLen = 1;
            tree[node].maxLen = 1;
            return;
        }

        int mid = start + (end - start) / 2;

        build(s, node * 2, start, mid);
        build(s, node * 2 + 1, mid + 1, end);

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1],
            mid - start + 1,
            end - mid
        );
    }

    void update(int node, int start, int end,
                int index, char value) {
        if (start == end) {
            tree[node].leftChar = value;
            tree[node].rightChar = value;
            tree[node].prefixLen = 1;
            tree[node].suffixLen = 1;
            tree[node].maxLen = 1;
            return;
        }

        int mid = start + (end - start) / 2;

        if (index <= mid) {
            update(node * 2, start, mid, index, value);
        } else {
            update(node * 2 + 1, mid + 1, end, index, value);
        }

        tree[node] = merge(
            tree[node * 2],
            tree[node * 2 + 1],
            mid - start + 1,
            end - mid
        );
    }

public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {
        int n = s.size();
        int q = queryIndices.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> answer(q);

        for (int i = 0; i < q; i++) {
            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            answer[i] = tree[1].maxLen;
        }

        return answer;
    }
};
