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
    unordered_map<int, int> mapping;
    TreeNode* BuildTreeHelper(vector<int> &postorder, vector<int> &inorder, int &index, int start, int end){
        if (index < 0 or start > end)
            return nullptr;
        int element = postorder[index--];
        TreeNode *root = new TreeNode(element);
        int position = mapping[element];
        root->right = BuildTreeHelper(postorder, inorder, index, position + 1, end);
        root->left = BuildTreeHelper(postorder, inorder, index, start, position - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            mapping[inorder[i]] = i;
        int postOrderIndex = postorder.size() - 1;
        return BuildTreeHelper(postorder, inorder, postOrderIndex, 0, postorder.size() - 1);
    }
};