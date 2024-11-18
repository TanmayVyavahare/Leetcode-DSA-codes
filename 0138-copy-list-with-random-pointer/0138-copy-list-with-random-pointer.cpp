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
private:
void insertcopynode(Node*head){
    Node *temp = head;
        while(temp != NULL){
         Node* copynode=new Node(temp->val);
         copynode->next = temp->next;
         temp->next = copynode;
         temp= temp->next->next; 
        }
}
private:
void connectrandomptr(Node*head){
    Node*temp = head;
    while(temp != NULL){
        Node*copy = temp->next;
        if(temp->random)copy->random = temp->random->next;
        else copy->random= NULL;
        temp = temp->next->next;
    }
}
private:
Node* extractll(Node*head){
    Node*temp = head;
    Node* newnode = new Node(-1);
    Node*res = newnode;
    while(temp != NULL){
        res->next = temp ->next;
        res = res->next;
        temp->next = temp ->next->next;
        temp = temp ->next;
    } 
    return newnode->next;
}
public:
    Node* copyRandomList(Node* head) {
        insertcopynode(head);
        connectrandomptr(head);
        return extractll(head);
    }
};