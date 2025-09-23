class Solution {
public:
    unordered_map<int,int> inMap;
    int preIndex = 0;
    
    TreeNode* build(vector<int>& preorder, int left, int right) {
        if (left > right) return nullptr;
        int rootVal = preorder[preIndex++];
        TreeNode* root = new TreeNode(rootVal);
        int inIndex = inMap[rootVal];
        root->left = build(preorder, left, inIndex - 1);
        root->right = build(preorder, inIndex + 1, right);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) inMap[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};
