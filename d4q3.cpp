class Node{
    public:
    string data;
    Node* prev;
    Node* next;
    Node(string data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
};

class BrowserHistory {
public:
    Node* curr=NULL; 
    BrowserHistory(string homepage) {
        curr=new Node(homepage);
    }
    
    void visit(string url) {
        Node* newNode=new Node(url);
        curr->next=newNode;
        newNode->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps--){
            if(curr->prev) curr=curr->prev;
            else break;
        }
        return curr->data;
    }
    
    string forward(int steps) {
        while(steps--){
            if(curr->next) curr=curr->next;
            else break;
        }
        return curr->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
