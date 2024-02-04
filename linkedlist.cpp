#include <iostream>
using namespace std;

class Node{
    int data;
    int next;

    public:
    Node(){
        data=0;
        next=NULL;
    }
    Node(Node &obj){
        data=obj.data;
        next=obj.next;
    }
    Node(int d){
        data=d;
        next=NULL;
    }
    void show(){
        cout<<"data is %d"<<data<<endl;
    }
};
class linkedList{
    void insertFromStart(Node* root, int val){
        if(root==NULL){
            Node* newNode=new Node(val);
        }
        else{
            Node temp=new Node(val);
            temp->next=head;
            head=temp;
        }
    }
    void insertToEnd(Node* root, int val){
        while(!root->next){
            root=root->next;
        }
        Node newNode=new Node(val);
        root->next=newNode;
    }
    void deleteFromPos(Node* root, int pos){
        Node* prev=NULL;
        Node* curr=root;
        
        while((pos-1)--&&curr!=NULL){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;
        free(curr);
    }
    void showList(Node* root){
        while(root->next!=NULL){
            cout<<root->val;
        }
    }
};
int main(){
    Node* ob=new Node(1);
    ob->show();
    // linkedList ob=new linkedList();


}