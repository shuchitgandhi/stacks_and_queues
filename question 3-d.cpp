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
void revSeq(Queue, int, int);

int main()
{
	int i, index1, index2, x;
	Queue Q;
	for(i=0;i<10;i++)
		Q.enqueue(i*2);
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
	if(index1!=index2)	revSeq(Q, 1, 5);
	cout<<"The new stack is : \n";
	while(!Q.isEmpty())
		cout<<Q.dequeue()<<" ";
	return 0;
}
void revSeq(Queue Q1, int index1, int index2)
{
	Queue Q2, Q3;
	int i, n, j;
	for(i=0;i<index1;i++)
		Q2.enqueue(Q1.dequeue());
	for(i=index1;i<=index2;i++)
		Q3.enqueue(Q1.dequeue());
	for(i=0, n=index2-index1+1;i<n;i++)
	{
		for(j=0;j<n-i-1;j++)
			Q3.enqueue(Q3.dequeue());
		Q2.enqueue(Q3.dequeue());
	}
	while(!Q1.isEmpty())
		Q2.enqueue(Q1.dequeue());
	while(!Q2.isEmpty())
		Q1.enqueue(Q2.dequeue());
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
 