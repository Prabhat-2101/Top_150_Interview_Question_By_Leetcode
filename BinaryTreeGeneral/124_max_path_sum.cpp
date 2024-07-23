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
class Solution {
public:
    int sumHelper(TreeNode* root,int &result){
        if(!root) return 0;
        int ml = max(0,sumHelper(root->left,result));
        int mr = max(0,sumHelper(root->right,result));
        result = max(result,root->val + ml + mr);
        return root->val + max(ml,mr);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int result = root->val;
        sumHelper(root,result);
        return result;
    }
};