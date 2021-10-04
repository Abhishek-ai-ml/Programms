#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* prev;
    node* next;
    node(int val){
        data=val;
        prev=NULL;
        next=NULL;
    }
};
void insert_at_head(node* &head,int val){
    node* n = new node(val);
    n->next=head;
    if(head!=NULL){
        head->prev=n;
    }
    head=n;
}

void insert_at_tail(node* &head,int val){
    if(head==NULL){
        insert_at_head(head,val);
        return;
    }
    node*n = new node(val);
    node* temp = head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void delete_at_head(node* &head){
    node* todelete = head;
    head=head->next;
    head->prev=NULL;

    delete todelete;
}

void deletion(node* &head,int pos){
    if(pos==1){
        delete_at_head(head);
        return;
    }
    node* temp = head;
    int flag=1;
    while(temp!=NULL && flag!=pos){
        temp=temp->next;
        flag++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}
int main()
{
    node* head=NULL;
    insert_at_head(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    insert_at_tail(head,4);
    insert_at_tail(head,5);
    display(head);
    deletion(head,1);
    deletion(head,4);
    display(head);
    return 0;
}