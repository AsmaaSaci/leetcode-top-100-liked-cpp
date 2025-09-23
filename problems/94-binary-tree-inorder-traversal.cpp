class Solution {
public:
    int maxSum;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        maxSum = max(maxSum, root->val + left + right);
        return root->val + max(left, right);
    }
    
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        dfs(root);
        return maxSum;
    }
};
