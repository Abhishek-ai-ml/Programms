#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};
void insert_at_tail(node* &head,int val){
    node* n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void insert_at_head(node* &head,int val){
    node*n =new node(val);
    n->next=head;
    head=n;
}
bool search(node* head,int key){
    node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
void delete_at_head(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}
void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        delete_at_head(head);
        return;
    }
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
node * recursive(node * &head){
    node * prevptr=NULL;
    node * currptr=head;
    node * nextptr;
    while(currptr!=NULL){
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}
node * reverseRecursive(node * &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node * newhead=reverseRecursive(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main()
{
    node* head=NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    display(head);
    node * newhead=reverseRecursive(head);
    display(newhead);
    return 0;
}