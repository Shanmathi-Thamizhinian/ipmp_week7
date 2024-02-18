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
    ListNode* reverseLL(ListNode* head){
        ListNode* next=head->next;
        ListNode* prev=head;
        
        prev->next=NULL;
        while(next!=NULL){
            ListNode* temp=next->next;
            next->next=prev;
            prev=next;
            next=temp;
        }
        return prev;
    }
    ListNode* findk(ListNode* temp, int k){
        while(temp!=NULL && --k){
            temp=temp->next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* kNode=findk(temp,k);
            if(kNode==NULL){
                if(prev) prev->next=temp;
                break;
            }
            ListNode* next=kNode->next;
            kNode->next=NULL;
            reverseLL(temp);
            if(temp==head) head=kNode;
            else prev->next=kNode;
            prev=temp;
            temp=next;
        }
        return head;   
    }
};
