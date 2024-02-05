/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
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
            
            int s=queue.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                Node* front=queue.front();
                temp.push_back(front->data);
                queue.pop();
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
            }
            for(int i=0;i<temp.size();i++)
            {
                cout<<temp[i]<<" ";
            }
            cout<<endl;
        }
    }
    
    void invertBinaryTree(Node* root){
     if(!root)return;
     invertBinaryTree(root->left);
     invertBinaryTree(root->right);
     if(root){
         Node* temp=root->left;
         root->left=root->right;
         root->right=temp;
     }
    }
    void showZigZag(Node* root){
        if(root==NULL){
            return;
        }   
        queue<Node*> queue;
        queue.push(root);
        int level=0;
        while(!queue.empty()){
            
            int s=queue.size();
            vector<int> temp;
            for(int i=0;i<s;i++){
                Node* front=queue.front();
                temp.push_back(front->data);
                queue.pop();
                if(front->left)
                    queue.push(front->left);
                if(front->right)
                    queue.push(front->right);
            }
            if(level%2!=0){
                // if the level is odd then reverse
                reverse(temp.begin(), temp.end());
            }
            for(int i=0;i<temp.size();i++)
            {
                cout<<temp[i]<<" ";
            }
            level++;
            cout<<endl;
        }
    }
};
int main()
{
    // inorder traversal of a bt
    BT* obj=new BT();
    Node* root=obj->createRoot(1);
    
    Node* left1 = obj->createLeft(root, 2);
    Node* right1= obj->createRight(root, 3);
    
    Node* left2 = obj->createLeft(left1, 4);
    Node* right2= obj->createRight(left1, 5);
    
    Node* left3 = obj->createLeft(right1, 6);
    Node* right3= obj->createRight(right1, 7);
    
    // obj->showTreeInorder(root);
    // cout<<"level order -> "<<endl;
    // obj->showLevelOrder(root);
    
    cout<<"level order -> "<<endl;
    obj->showLevelOrder(root);
    
    obj->invertBinaryTree(root);
    obj->showLevelOrder(root);
    
    return 0;
}