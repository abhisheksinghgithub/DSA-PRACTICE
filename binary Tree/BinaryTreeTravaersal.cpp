#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};
Node* createNode(Node* root){
    cout<<"enter data\n";
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"enter the data for left node for"<<root->data<<endl;
    root->left=createNode(root->left);
    cout<<"enter the data for right node for"<<root->data<<endl;
    root->right=createNode(root->right);
}
void LOT(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
         Node* temp=q.front();
         q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
           cout<<temp->data<<" ";
           if(temp->left)
           q.push(temp->left);
           if(temp->right)
           q.push(temp->right);
        }
    }
}
void inOrder(Node* root){
    
   if(root==NULL){
    return;
   }
   inOrder(root->left);
   cout<<root->data;
   inOrder(root->right);
}
//pos order lrn
//preorder nlr

int main(){
    Node* root=NULL;
    root=createNode(root);
    LOT(root);
    cout<<endl;
    inOrder(root);

return 0;
}
