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
public:

    ListNode* findN(ListNode* temp, int n){
        while(temp!=NULL && --n) temp=temp->next;
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0) return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next){
            tail=tail->next;
            len++;
        }
        if(k%len==0) return head;
        k=k%len;
        tail->next=head;
        ListNode* last=findN(head,len-k);
        head=last->next;
        last->next=NULL;
        return head;
    }
};
