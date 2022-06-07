#include<iostream>
using namespace std;
//declaring node data type
class node
{
    public:
    int data;
    node *next;
    node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
   ~node()
   {
        int value=this->data;
        this->next=NULL;
   }
};
//for innsertion at head
void insertAtHead(node*& head,int d)
{
    node *temp=new node(d);
    temp->next=head;
    head=temp;

}
void print(node* head)
{
  node *temp=head;
  
  while (temp!=NULL)
  {
      cout<<temp->data<<" ";
      temp=temp->next;
  }
  cout<<endl;

}
void insertAtTail(node * & tail,int d)
{
  node*temp=new node(d);
  tail->next=temp;
  temp->next =NULL;
  tail=temp;
 
}
void insertAtPosi(node*head,node*tail,int pos,int value)
{
    if(pos==1)
    {
        insertAtHead(head,value);
    }
  node * nToInsert=new node(value);
  node *temp=head;
  int cnt=1;
  while(cnt<pos-1)
  {
      temp=temp->next;
      cnt++;
  }
  if(temp->next==NULL)
  {
      insertAtTail(tail,value);
  }
  //insertion
  nToInsert->next=temp->next;
  temp->next=nToInsert;

}
void toDeleteNode(node *& head, int position)
{
  
  if(position==1)
  {
      node *temp=head;
     head=head->next;
     delete temp;

  }
  else{
  int cnt=1;
  node*pre=NULL;
  node*curr=head;
  while (cnt<position)
  {
    pre=curr;
    curr=curr->next;
    cnt++;

  }
  pre->next=curr->next;
  delete curr;

  }
}
int main()
{
    //creating a object us heap
   node* node1=new node(7);
    
    node *head=node1;
    node *tail=node1;
  // insertion at head
   insertAtHead(head,15);
   insertAtHead(head,14);
  // insertion at tail
   insertAtTail(tail,3);
   insertAtTail(tail,4);
  // insertion at specific position
   insertAtPosi(head,tail,4,1);
   print(head);
   cout<<endl;
   performing delete opration
   toDeleteNode(head,4);
   print(head);
}
