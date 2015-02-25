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

class Queue{
		Node* head;
		Node* tail;
		Node* createNewNode(int);
	public:
		Queue();
		void enqueue(int);
		int dequeue();
		bool isEmpty();
};
int main()
{
	Stack S;
	Queue Q;
	S.push(1);S.push(2);S.push(3);S.push(4);S.push(5);
	Q.enqueue(1);Q.enqueue(2);Q.enqueue(3);Q.enqueue(4);Q.enqueue(5);
	cout<<"The stack is : \n";
	while(!S.isEmpty())
		cout<<S.pop()<<" ";
	cout<<"\nThe queue is : \n";
	while(!Q.isEmpty())
		cout<<Q.dequeue()<<" ";
	return 0;
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
 
 
Queue::Queue()
{
	head = '\0';
	tail = '\0';
}

Node* Queue::createNewNode(int x)
{
	Node* y = new Node(x);
	if(y=='\0') cout<<"Node not created...\n"; 
	return y;
}

void Queue::enqueue(int x)
{
	Node* z = createNewNode(x);
	if(head=='\0')
	{
		head = z;
		tail = z;
	}
	else
	{
		tail->setNext(z);
		tail = z;
	}
}

int Queue::dequeue()
{
	if(head=='\0')
	{
		cout<<"Queue empty...\n";	
	}
	else
	{
		Node* x = head;
		int z = head->getData();
		head = head->getNext();
		delete x;
		return z;
	}
	return -1;
}

bool Queue::isEmpty()
{
	if(head=='\0')
		return true;
	else
		return false;
}
 