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
    unordered_map<int,int> umap;
    int find_height(TreeNode* root){
        if(!root) return 0;
        int lh = find_height(root->left);
        int rh = find_height(root->right);
        return max(lh,rh) + 1;
    }
    void create_right_view(TreeNode* root,int ht){
        if(root == NULL) return ;
        if(umap.find(ht) == umap.end()) umap[ht] = root->val;
        create_right_view(root->right,ht+1);
        create_right_view(root->left,ht+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        int height = find_height(root);
        vector<int> result(height,0);
        create_right_view(root,0);
        for(auto it: umap){
            result[it.first] = it.second;
        }
        return result;
    }
};