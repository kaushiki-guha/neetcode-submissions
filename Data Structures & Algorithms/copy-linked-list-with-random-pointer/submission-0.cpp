/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> map;
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr; //checks for empty list
        if(map.count(head)) return map[head]; //checks if head already exists

        Node* copy = new Node(head->val); //copy of node
        map[head] = copy; //maps next node into copy
        copy-> next = copyRandomList(head->next);
        copy->random = map[head->random];
        return copy;
    }
};
