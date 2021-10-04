#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* pre;
    node* next;
    node(int val){
        data=val;
        pre=NULL;
        next=NULL;
    }
};

void insert(node* head, int val){
    node* curr=head;
    node* n=new node(val);
    if(curr==NULL){
        
    }
}