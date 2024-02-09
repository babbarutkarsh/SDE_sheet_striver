#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(){
        data=0;
        next=nullptr;
    }
    Node(Node &obj){
        data=obj.data;
        next=obj.next;
    }
    Node(int d){
        data=d;
        next=nullptr;
    }
    void show(){
        cout<<"data is %d"<<data<<endl;
    }
};
class linkedList{
    void insertFromStart(Node* root, int val){
        if(root==nullptr){
            Node* newNode=new Node(val);
        }
        else{
            Node* temp=new Node(val);
            temp->next=root;
            root=temp;
        }
    }
    void insertToEnd(Node* root, int val){
        while(!root->next){
            root=root->next;
        }
        Node* newNode=new Node(val);
        root->next=newNode;
    }
    void deleteFromPos(Node* root, int pos){
        Node* prev=nullptr;
        Node* curr=root;
        
        while((pos--)&&curr!=nullptr){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=nullptr;
        free(curr);
    }
    void showList(Node* root){
        while(root->next!=nullptr){
            cout<<root->data;
        }
    }
};
void showList(Node* head){
    while(head!=NULL){
        cout<<head->data<<endl;
        head=head->next;
    }    
}
Node* reverseLL(Node* root){
    if(!root)return NULL;
    // reverse nodes 1->2->3->4->5
    Node* prev=NULL;
    Node* curr=root;
    Node* temp;
    while(curr!=NULL){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    root=prev;
    return root;
}
Node* middleLL(Node* root){
    Node* slow=root;
    Node* fast=root;
    while(fast and fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<slow->data<<endl;
    return slow;
}
Node* mergeSortedLL(Node* one, Node* two){
 Node* ptr;
 if(one->data<two->)
    
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp=head, *ptr=head;
        while(temp){
            size++;
            temp=temp->next;
        }
        int l=size-n;
        if(l<0)
            return head;
        if(l==0){
            head=head->next;
            return head;
        }
        ptr=head;
        cout<<l<<endl;
        l=l-1;
        while(l){
            cout<<ptr->val<<endl;
            ptr=ptr->next;
            l--;
        }
        ptr->next=ptr->next->next;
        return head;
    }
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* out=NULL;
        ListNode* ans;
        int carry=0;
        while(l1 or l2 or carry){
            ListNode* n=new ListNode();
            int l1v=0;
            int l2v=0;
            if(l1){
                l1v=l1->val;
                l1=l1->next;
            }
            if(l2){
                l2v=l2->val;
                l2=l2->next;
            }
            // cout<<carry<<endl;
            int sum=l1v+l2v+carry;
            carry=sum/10;
            sum=sum%10;
            n->val=sum;
            if(!out){
                out=n;
                ans=out;
            }
            else{
                out->next=n;
                out=out->next;
            }
        }
        return ans;
    }
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
            
        ListNode * ptr = list1;
        
        if(list1 -> val > list2 -> val){
            ptr = list2;
            list2 = list2 -> next;
        }
        else{
            list1 = list1 -> next;
        }
        
        ListNode *curr = ptr;
        
        while(list1 &&  list2)
        {
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;      
        }
        if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
        return ptr;
}
int main(){
    Node* one=new Node(1);
    Node* two=new Node(2);
    Node* three=new Node(3);
    Node* four=new Node(4);
    Node* five=new Node(5);
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=five;
    // Node* rev=reverseLL(one);
    // showList(one);
    middleLL(one);
}