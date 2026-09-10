class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }

private:
    pair<int, int> dfs(TreeNode* node, int& count) {
        if (!node) return {0, 0};

        auto left = dfs(node->left, count);
        auto right = dfs(node->right, count);

        int sum = node->val + left.first + right.first;
        int nodes = 1 + left.second + right.second;

        if (sum / nodes == node->val)
            count++;

        return {sum, nodes};
    }
};
