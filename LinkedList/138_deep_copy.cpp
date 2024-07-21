class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> umap;
        
        Node* newHead = head;
        while (newHead) {
            umap[newHead] = new Node(newHead->val);
            newHead = newHead->next;
        }
        
        newHead = head;
        while (newHead) {
            umap[newHead]->next = umap[newHead->next];
            umap[newHead]->random = umap[newHead->random];
            newHead = newHead->next;
        }
        return umap[head];
    }
};