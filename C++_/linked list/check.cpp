#include<bits/stdc++.h>
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
void insert(node* &head,int val){
    node*n=new node(val);
    node* curr=head;
    node* nextptr=curr->next;
    while(curr!=NULL && curr->data!=val){
        curr=nextptr;
        nextptr=nextptr->next;

    }
    n->next=nextptr;
    if(curr!=NULL){
        head=n;
    }
    else
    {
        curr->next=n;
    }
}

void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
void insert_at_head(node* &head,int val){
    node*n =new node(val);
    n->next=head;
    head=n;
}

int main()
{
    node* head=NULL;
    insert_at_head(head,1);
    insert_at_head(head,2);
    display(head);
    return 0;
}