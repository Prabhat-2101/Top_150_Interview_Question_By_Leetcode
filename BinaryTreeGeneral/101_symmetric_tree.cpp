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
    bool checkSymmetricTree(TreeNode* l,TreeNode* r){
        if(l==NULL && r==NULL) return true;
        if(l==nullptr || r==nullptr) return false;
        if(l->val==r->val) return checkSymmetricTree(l->left,r->right)&&checkSymmetricTree(l->right,r->left);
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return false;
        if(root->left==nullptr && root->right==nullptr)return true;
        if(root->left==nullptr || root->right==nullptr)return false;
        return checkSymmetricTree(root->left,root->right);
    }
};