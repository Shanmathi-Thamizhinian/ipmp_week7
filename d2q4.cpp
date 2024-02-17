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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *curr=head->next;
        ListNode *prev=head;
        ListNode* temp;
        prev->next=NULL;
        while(curr!=NULL){
            temp=curr->next; //3
            curr->next=prev; //2 to 1
            prev=curr; //2
            curr=temp; //3
        }
        return prev;
    }
};
