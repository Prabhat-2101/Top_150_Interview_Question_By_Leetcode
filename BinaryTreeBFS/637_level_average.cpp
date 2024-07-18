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
    int find_height(TreeNode* root){
        if(!root) return 0;
        int lh = find_height(root->left);
        int rh = find_height(root->right);
        return max(lh,rh) + 1;
    }

    unordered_map<int,pair<double,int>> umap;
    void generate_sum(TreeNode* root,int height){
        if(root == NULL) return;
        umap[height].first += root->val;
        umap[height].second += 1;
        generate_sum(root->left,height+1);
        generate_sum(root->right,height+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        int height = find_height(root);
        vector<double> result(height);
        generate_sum(root,0);
        for(const auto it: umap){
            result[it.first] = it.second.first / it.second.second;
        }
        return result;
    }
};