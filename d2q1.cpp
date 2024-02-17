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
        if(head==NULL){
            return new ListNode(val);
        }
        ListNode* tail=head;
        while(tail->next!=NULL){
            tail=tail->next;
        }
        tail->next=new ListNode(val);
        return head;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0,sum;
        ListNode* head=(struct ListNode*)malloc(sizeof(struct ListNode));
        head=NULL;
        while(l1!=NULL && l2!=NULL){
            sum=(l1->val+l2->val+carry)%10;
            carry=(l1->val+l2->val+carry)/10;
            head=insertAtEnd(head,sum);
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            sum=(l1->val+carry)%10;
            carry=(l1->val+carry)/10;
            head=insertAtEnd(head,sum);
            l1=l1->next;
        }
        while(l2!=NULL){
            sum=(l2->val+carry)%10;
            carry=(l2->val+carry)/10;
            head=insertAtEnd(head,sum);
            l2=l2->next;
        }
        if(carry!=0) head=insertAtEnd(head,carry);
        return head;
    }
};
