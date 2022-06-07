#include<iostream>
using namespace std;
class node
{
    public:
    int data;
    node* next;
    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};
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
/*void insertAtTail(node * &tail,int value)
{
    node* temp= new node(value);
    tail->next=temp;
    temp->next=NULL;
    tail=temp;
    
}*/void insertAtTail(node * & tail,int d)
{
  node*temp=new node(d);
  tail->next=temp;
  temp->next =NULL;
  tail=temp;
}
node* IfCylcle(node* &head)
{
    node*slow=head;
    node* fast=head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
        fast=fast->next;}
        slow=slow->next;
        if(slow==fast)
        {
            //cout<<"present"<<slow->data;
            return slow;
        }
       
 //cout<<"present"<<slow->data;
    }
     return NULL;
}
int startNdoeCy(node*head)
{
    node * fast=IfCylcle(head);
    node * slow=head;
    while(slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return slow->data;
}

int main(){

node * tail=new node(5);
node * head=tail;
insertAtTail(tail,6);
insertAtTail(tail,7);
insertAtTail(tail,8);
insertAtTail(tail,9);
insertAtTail(tail,10);

 print (head);
 cout<<endl;
 //making this ll cyclic
 tail->next=head->next->next;
 if(IfCylcle(head)!=NULL)
 {
     cout<<"the cycle is presnt"<<endl;
 }else{
     cout<<"cycle is not present"<<endl;
 }
 cout<<endl;
 cout<<startNdoeCy(head);
return 0;
}
