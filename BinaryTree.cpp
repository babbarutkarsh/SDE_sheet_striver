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
    bool hasPathSum(Node* root, int target){
        if(root==NULL)return false;
        if(root->data==target and !root->left and !root->right){
            return true;
        }
        return hasPathSum(root->left,target-(root->data))+hasPathSum(root->right,target-(root->data));
    }
    void identicalBT(Node* one, Node* two){
        if(one==NULL and two==NULL){
            return true;
        }
        if(one->data!=two->data){
            return false;
        }
        return identicalBT(one->left,two->left)+identicalBT(one->right,two->right);
    }
    
    bool symmetricalHelper(Node* left, Node* right){
        if(!left&&!right)
            return true;
        if(left->data!=right->data)
            return false;
        return symmetricalHelper(left->right,right->left)&&symmetricalHelper(left->left,right->right);
    }
    bool symmetricalBT(Node* root){
        if(!root->left&&!root->right)return true;
        else if(!root->left || !root->right)return false;
        return symmetricaHelper(root->left, root->right);
    }
    
    Node* LCAofTwoNodesBST(int one, int two, Node* root){
        // given a BST find LCA 
        if(!root)return NULL;

        if(one<root->data && two<root->data){
            // move left
            return LCAofTwoNodesBST(one,two,root->left);
        }
        else if(one>root->data && two>root->data){
            return LCAofTwoNodesBST(one,two,root->right);
        }
        else{
            // found
            return root;
        }
        return NULL;
    }
    Node* LCAofTwoNodes(Node* one, Node* two, Node* root){
        // tree is not BST now
        // search node in left and right halves if you get both return Node
        if(!root)return NULL;
        
        if(root==one||root==two)return root;
        
        Node* left=search(one,two,root->left);
        Node* right=search(one,two,root->right);
        
        if(left&&right)return root;
        
        return left?left:right;
    }
    void sumRootToLeafBT(Node* root, int temp, int& sumTotal){
        //              1
        //          2       3
        //      4    5
        //    6
        // sum= 1246+125+13
        if(!root)return;
        if(!root->right&&!root->left){
            sumTotal+=temp;
            return;
        }
        temp=temp*10+root->data;
        sumRootToLeafBT(root->left);
        sumRootToLeafBT(root->right);
        return;
    }
    bool twoSumBT(int target, Node* root){
        
    }
    int maxDepth(Node* root){
        if(root==NULL){
            return 0;
        }
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    int minDepth(Node* root){
        if(root==NULL){
            return 0;
        }
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        
        if(left==0||right==0)return max(left,right);
        
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
    int findGreatestIndex(vector<int> v, int l, int h){
        int mx=INT_MIN;int ind=INT_MIN;
        for(int i=l;i<h;i++){
            if(v[i]>mx){
                mx=v[i];
                ind=i;
            }
        }
        return ind;
    }
    Node* BTfromInorder(vector<int> v, int l, int h){
       if(l>h)return NULL;        
       int i=findGreatestIndex(v,l,h);
       Node* root=new Node(v[i]);
       
       root->left=BTfromInorder(v,0,i-1);
       root->right=BTfromInorder(v,i+1,h);
       
        return h;
    }
    Node* sortedArrayToBST(vector<int> v, int l,int h){
        
        int mid=(l+h)/2;
        Node* root=new Node(v[mid]);
        root->left=sortedArrayToBST(v,m+1,h);
        root->right=sortedArrayToBST(v,l,m-1);
        
        return root;
    }
    // medium to hard
    Node* BTfromInorderAndPostorder(){
        
    }
    Node* kthSmallestinBST(){
        
    }
    void BTtoLL(){
        
    }
    Node* recoverBST(){
        
    }
    void hasPathSumStore(vector<string>& v, string temp, Node* root, int target){
        if(root==NULL)return;
        temp+=to_string(root->data)+" ";
        if(root->data==target and !root->left and !root->right){
            v.push_back(temp);
        }
        else{
            hasPathSumStore(v,temp,root->left,target-(root->data));
            hasPathSumStore(v,temp,root->right,target-(root->data));
        }
    }
    void allPaths(Node* head, int target){
        vector<string> out={};
        hasPathSumStore(out,"",head,target);
        
        for(int i=0;i<out.size();i++){
            cout<<out[i]<<endl;
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
    
    Node* left1 = obj->createLeft(root, 5);
    Node* right1= obj->createRight(root, 3);
    
    Node* left2 = obj->createLeft(left1, 4);
    Node* right2= obj->createRight(left1, 5);
    
    Node* left3 = obj->createLeft(right1, 6);
    Node* right3= obj->createRight(right1, 7);
    
    // obj->showTreeInorder(root);
    // cout<<"level order -> "<<endl;
    // obj->showLevelOrder(root);
    
    // cout<<"level order -> "<<endl;
    obj->showLevelOrder(root);
    
    // obj->invertBinaryTree(root);
    // obj->showLevelOrder(root);
    
    obj->allPaths(root,10);
    
    return 0;
}