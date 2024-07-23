class Solution {
public:
    Node* getnextnode(Node* root) {
        while (root != NULL) {
            if (root->left != NULL)
                return root->left;
            if (root->right != NULL)
                return root->right;

            root = root->next;
        }
        return root;
    }

    Node* connect(Node* root) {
        if (root == NULL)
            return root;
        Node* nextnode = getnextnode(root->next);

        if (root->left != NULL) {
            if (root->right != NULL)
                root->left->next = root->right;
            else
                root->left->next = nextnode;
        }

        if (root->right != NULL)
            root->right->next = nextnode;

        connect(root->right);
        connect(root->left);
        return root;
    }
};