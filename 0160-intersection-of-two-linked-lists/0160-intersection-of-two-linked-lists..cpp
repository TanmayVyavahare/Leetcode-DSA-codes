/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private: 
    ListNode *collisionpt(ListNode *headA, ListNode *headB,int d) {
        while(d){
            d--;
            headB = headB->next;
        }
        while(headA!=headB){
            headA= headA->next;
            headB= headB->next;
        }
        return headA;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t1 = headA;
        ListNode *t2 = headB;
        int N1=0,N2=0;
        while(t1!= NULL){
            N1++;
            t1=t1->next;
        }
        while(t2!= NULL){
            N2++;
            t2=t2->next;
        }
        if(N1<N2) return collisionpt(headA,headB,N2-N1);
        else return collisionpt(headB,headA,N1-N2);


    }
};