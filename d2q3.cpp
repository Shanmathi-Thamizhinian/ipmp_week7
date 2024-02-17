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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* prev;
        int count=0;
        while(curr!=NULL){
            count++;
            curr=curr->next;
        }
        ListNode* del=head;
        int pos=0;
        while(del!=NULL){
            pos++;
            if(pos==count-n+1) break;
            prev=del;
            del=del->next;
        }
        if(prev==NULL){
            head=del->next;
            delete del;
            return head;
        }
        prev->next=del->next;
        del->next=NULL;
        delete del;
        return head;

    }
};
