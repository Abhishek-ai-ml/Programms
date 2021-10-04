#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* next;
};

node* newNode(int data)
{
	node* newnode = new node();
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

int isEmpty(node* root)
{
	return !root;
}

void push(node** root, int data)
{
	node* node = newNode(data);
	node->next = *root;
	*root = node;
	cout << data << " pushed to stack\n";
}

int pop(node** root)
{
	if (isEmpty(*root))
		return INT_MIN;
	node* temp = *root;
	*root = (*root)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

int peek(node* root)
{
	if (isEmpty(root))
		return INT_MIN;
	return root->data;
}

// Driver code
int main()
{
	node* root = NULL;

	push(&root, 20);
	push(&root, 40);
	push(&root, 60);
    push(&root, 80);

	cout<<"Element popped from stack : "<<pop(&root)<<endl;
	cout<<"Elements are in stack : ";
	
	while(!isEmpty(root))
	{
		cout<<peek(root)<<" ";
		pop(&root);
	}

	return 0;
}

