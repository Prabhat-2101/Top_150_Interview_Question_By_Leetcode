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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return result;
        bool l_to_r = true;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            for(int i=0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                if(front){
                    int idx = l_to_r?i:size-i-1;
                    temp[idx] = front->val;
                    if(front->left)
                        q.push(front->left);
                    if(front->right)
                        q.push(front->right);
                }
            }
            l_to_r = !l_to_r;
            result.push_back(temp);
        }
        return result;
    }
};