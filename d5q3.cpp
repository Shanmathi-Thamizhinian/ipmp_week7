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

    void makeCopy(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=new Node(temp->val);
            copyNode->next=temp->next;
            temp->next=copyNode;
            temp=temp->next->next;
        }
    }

    void pointRandom(Node* head){
        Node* temp=head;
        while(temp!=NULL){
            Node* copyNode=temp->next;
            if(temp->random) copyNode->random=temp->random->next;
            else copyNode->random=NULL;
            temp=temp->next->next;
        }
    }

    Node* finalClone(Node* head){
        Node* dummy=new Node(-1);
        Node* temp=head;
        Node* curr=dummy;
        while(temp!=NULL){
            curr->next=temp->next;
            curr=curr->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        makeCopy(head);
        pointRandom(head);
        return finalClone(head);
    }
};
