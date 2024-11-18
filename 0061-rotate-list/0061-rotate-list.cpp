/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    ListNode* getlastnode(ListNode* head,int dif){
        ListNode* temp = head;
        int cnt =1;
        while(temp!=NULL){
            if(cnt == dif) return temp;
            cnt++;
            temp = temp->next;
        }
        return temp;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail = head;
        int len =1;
        while(tail->next !=NULL){
            
            tail =  tail->next;
            len++;
        }
        if(k%len == 0) return head;
        k= k%len;
        tail->next = head;
        ListNode*lastnode = getlastnode(head,len-k);
        head = lastnode->next;
        lastnode->next = NULL;
        return head;
    }
};