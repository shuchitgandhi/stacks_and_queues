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
void revSeq(Stack, int, int);

int main()
{
	int i, index1, index2, x;
	Stack S;
	for(i=0;i<10;i++)
		S.push(i*2);
	cout<<"Enter index 1 : ";
	cin>>index1;
	cout<<"Enter index 2 : ";
	cin>>index2;
	if(index1>index2)
	{
		x = index1;
		index1 = index2;
		index2 = x;
	}
	if(index1!=index2)	revSeq(S, index1, index2);
	cout<<"The new stack is : \n";
	while(!S.isEmpty())
		cout<<S.pop()<<"\n";
	return 0;
}
void revSeq(Stack S1, int index1, int index2)
{
	Stack S2, S3;
	int i;
	while(!S1.isEmpty())
		S2.push(S1.pop());
	for(i=0;i<index1;i++)
		S3.push(S2.pop());
	for(i=index1;i<=index2;i++)
		S1.push(S2.pop());
	while(!S1.isEmpty())
		S3.push(S1.pop());
	while(!S3.isEmpty())
		S2.push(S3.pop());
	while(!S2.isEmpty())
		S1.push(S2.pop());
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
 