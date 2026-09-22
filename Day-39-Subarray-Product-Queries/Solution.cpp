#include <vector>
using namespace std;

struct Node {
    int prod;
    int cnt[5];

    Node() {
        prod = 1;
        for (int i = 0; i < 5; ++i)
            cnt[i] = 0;
    }
};

class Solution {
    int n, k_mod;
    vector<Node> tree;

    Node mergeNodes(const Node& left, const Node& right) {
        Node res;

        res.prod = (left.prod * right.prod) % k_mod;

        for (int i = 0; i < k_mod; ++i)
            res.cnt[i] = left.cnt[i];

        for (int i = 0; i < k_mod; ++i) {
            int rem = (left.prod * i) % k_mod;
            res.cnt[rem] += right.cnt[i];
        }

        return res;
    }

    void build(const vector<int>& nums, int node, int start, int end) {
        if (start == end) {
            int val = nums[start] % k_mod;
            tree[node].prod = val;
            tree[node].cnt[val] = 1;
            return;
        }

        int mid = start + (end - start) / 2;

        build(nums, node * 2, start, mid);
        build(nums, node * 2 + 1, mid + 1, end);

        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            int rem = val % k_mod;

            for (int i = 0; i < 5; ++i)
                tree[node].cnt[i] = 0;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;
            return;
        }

        int mid = start + (end - start) / 2;

        if (idx <= mid)
            update(node * 2, start, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, end, idx, val);

        tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return Node();

        if (l <= start && end <= r)
            return tree[node];

        int mid = start + (end - start) / 2;

        Node leftRes = query(node * 2, start, mid, l, r);
        Node rightRes = query(node * 2 + 1, mid + 1, end, l, r);

        return mergeNodes(leftRes, rightRes);
    }

public:
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        n = nums.size();
        k_mod = k;

        tree.assign(4 * n, Node());

        build(nums, 1, 0, n - 1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            int idx = q[0];
            int val = q[1];
            int start = q[2];
            int x = q[3];

            update(1, 0, n - 1, idx, val);

            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};
