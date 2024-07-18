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
    void preorder(TreeNode *root, int k,int& count,int &res){
        if(!root || count>=k) return;
        preorder(root->left,k,count,res);
        count += 1;
        if(count==k){
            res = root->val; return;
        } 
        preorder(root->right,k,count,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = root->val,count=0;
        preorder(root,k,count,res);
        return res;
    }
};