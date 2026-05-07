class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        unordered_map<Node*, Node*> mapping;
        
        // Step 1: create all nodes
        Node* curr = head;
        while (curr) {
            mapping[curr] = new Node(curr->val);
            curr = curr->next;
        }
        
        // Step 2: assign pointers
        curr = head;
        while (curr) {
            mapping[curr]->next = mapping[curr->next];
            mapping[curr]->random = mapping[curr->random];
            curr = curr->next;
        }
        
        return mapping[head];
    }
};