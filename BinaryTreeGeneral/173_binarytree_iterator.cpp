/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<int> inorder; int ptr = 0;
    void buildInorder(TreeNode* root){
        if(!root) return;
        buildInorder(root->left);
        inorder.push_back(root->val);
        buildInorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        buildInorder(root);
    }
    
    int next() {
        return inorder[ptr++];
    }
    
    bool hasNext() {
        return ptr<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */