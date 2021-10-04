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

void insert_at_head(node* &head,int val){
    node*n =new node(val);
    n->next=head;
    head=n;
}
node* insert(node* &head, int val){
    node* n=new node(val);
    node* curr=head;
    node* pre=NULL;
    while(curr!=NULL && val>curr->data){
        pre=curr;
        curr=curr->next;
    }
    n->next=curr;
    if(pre==NULL){
        head=n;
    }
    else
    {
        pre->next=n;
    }
    return head;
}
void display(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}

void deletion(node* &head,int val){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
       node* temp=head;
       node* todelete=temp;
        temp=temp->next;
        delete todelete;
        head=NULL;
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
int main()
{
    node* head=NULL;
    insert_at_head(head,4);
    insert_at_head(head,2);
    insert_at_head(head,1);
    display(head);
    node* newhead=insert(head,3);
    display(newhead);
    deletion(head,3);
    display(head);
    deletion(head,4);
    deletion(head,2);
    display(head);
    deletion(head,1);
    display(head);
    return 0;

}