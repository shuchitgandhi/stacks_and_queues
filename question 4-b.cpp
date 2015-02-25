#include<iostream>
using namespace std;
class Node{
		int data;
		Node* next;
	public:
		Node(int);
		int getData();
		Node* getNext();	
		void setNext(Node*);	
};

class Stack{
		Node* top;
		Node* createNewNode(int);
	public:
		Stack();		
		void push(int);
		int pop();
		bool isEmpty();
};
void transformS(Stack, int[], int);

int main()
{
	Stack S;
	int i, order[10];
	for(i=0;i<10;i++)
		S.push(i);
	cout<<"Enter 10 numbers from (1-10) : ";
	for(i=0;i<10;i++)
		cin>>order[i];
	transformS(S, order, 10);
	return 0;
}
void transformS(Stack S1, int order[], int size)
{
	Stack S2, S3;
	int i, j, flag=0;
	for(i=0;i<size;i++)
	{
		if(flag==0)
		{
			for(j=size-1-i;j>order[i];j--)
				S2.push(S1.pop());
			S3.push(S1.pop());
			while(!S1.isEmpty())
				S2.push(S1.pop());
			for(j=i+1;j<size;j++)
				if(order[i]<order[j])
					order[j]--;
			flag = 1;
		}
		else
		{
			for(j=0;j<order[i];j++)
				S1.push(S2.pop());
			S3.push(S2.pop());
			while(!S2.isEmpty())
				S1.push(S2.pop());
			for(j=i+1;j<size;j++)
				if(order[i]<order[j])
					order[j]--;
			flag = 0;
		}
	}
	while(!S3.isEmpty())
		S1.push(S3.pop());
	cout<<"The new stack is : \n";
	while(!S1.isEmpty())
		cout<<S1.pop()<<" ";
}
Node::Node(int x)
{
	data = x;
	next = '\0';
}

int Node::getData()
{
	return data;
}

Node* Node::getNext()
{
	return next;
}

void Node::setNext(Node* x)
{
	next = x;
}
Stack::Stack()
{
	top = '\0';
}

Node* Stack::createNewNode(int x)
{
	Node* y = new Node(x);
	if(y=='\0') cout<<"Node not created...\n"; 
	return y;
}

void Stack::push(int x)
{
	Node* z = createNewNode(x);
	if(top=='\0') top = z;
	else
	{
		z->setNext(top);
		top = z;
	}
}

int Stack::pop()
{
	if(top=='\0')
		cout<<"Stack empty..";
	else
	{
		Node* x = top;
		int z = x->getData();
		top = top->getNext();
		delete x;
		return z;
	}
	return -1;
}

bool Stack::isEmpty()
{
	if(top=='\0')
		return true;
	else
		return false;
}