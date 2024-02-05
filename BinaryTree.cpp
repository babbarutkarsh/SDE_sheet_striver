#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
  
  public:
  int data;
  Node* left;
  Node* right;

  Node(){
      data=0;
      left=NULL;
      right=NULL;
  }
  Node(int val){
      data=val;
      left=NULL;
      right=NULL;
  }
};
class BT{
    public:
    Node* createRoot(int val){
        Node* root=new Node();
        root->data=val;
        return root;
    }
    public:
    Node* createLeft(Node* root, int val){
        Node* left=new Node(val);
        root->left=left;
        return left;
    }
    public:
    Node* createRight(Node* root, int val){
        Node* right=new Node(val);
        root->right=right;
        return right;
    }
    // inorder 
    public:
    void showTreeInorder(Node* root){
        if(root==NULL)
            return;
        showTreeInorder(root->left);
        cout<<root->data<<endl;
        showTreeInorder(root->right);
    }
    // pre order and post order can be done by just replacing cout up and down
    // level order traversal
    void showLevelOrder(Node* root){
        if(root==NULL){
            return;
        }   
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty()){
            Node* front=queue.front();
            cout<<front->data<<endl;
            queue.pop();
            if(front->left){
                queue.push(front->left);
            }
            if(front->right){
                queue.push(front->right);
            }
        }
    }
};
int main()
{
    // inorder traversal of a bt
    BT* obj=new BT();
    Node* root=obj->createRoot(10);
    
    Node* left1 = obj->createLeft(root, 9);
    Node* right1= obj->createRight(root, 8);
    
    Node* left2 = obj->createLeft(left1, 9);
    Node* right2= obj->createRight(left1, 8);
    
    
    obj->showTreeInorder(root);
    cout<<"level order -> "<<endl;
    obj->showLevelOrder(root);
    return 0;
}