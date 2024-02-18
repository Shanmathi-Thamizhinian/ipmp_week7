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

    ListNode* insertAtEnd(ListNode* head, int val){
        if(head==NULL) return new ListNode(val);
        ListNode* prev=head;
        while(prev->next!=NULL) prev=prev->next;
        prev->next=new ListNode(val);
        return head;
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       ListNode* head=NULL;
       ListNode* l1=list1, *l2=list2;
       if(list1==NULL && list2==NULL) return NULL;
       if(list1==NULL && list2!=NULL) return list2;
       if(list1!=NULL && list2==NULL) return list1;
       while(l1!=NULL && l2!=NULL){
           if(l1->val<l2->val){
            head=insertAtEnd(head,l1->val);
            l1=l1->next;
            }
            else if(l1->val>l2->val){
            head=insertAtEnd(head,l2->val);
            l2=l2->next;
            }
            else{
            head=insertAtEnd(head,l1->val);
            head=insertAtEnd(head,l2->val);
            l1=l1->next;
            l2=l2->next;
            }
       }
       while(l1!=NULL){
           head=insertAtEnd(head,l1->val);
            l1=l1->next;
       }
       while(l2!=NULL){
           head=insertAtEnd(head,l2->val);
            l2=l2->next;
       }
       return head;
    }
};
