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
void transformQ(Queue, int[], int);

int main()
{
	Queue Q;
	int i, order[10];
	for(i=0;i<10;i++)
		Q.enqueue(i);
	cout<<"Enter 10 numbers from (1-10) : ";
	for(i=0;i<10;i++)
		cin>>order[i];
	transformQ(Q, order, 10);
	return 0;
}
void transformQ(Queue Q1, int order[], int size)
{
	Queue Q2, Q3;
	int flag = 0, i, j;
	for(i=0;i<size;i++)
	{
		if(flag==0)
		{
			for(j=0;j<order[i];j++)
				Q2.enqueue(Q1.dequeue());
			Q3.enqueue(Q1.dequeue());
			while(!Q1.isEmpty())
				Q2.enqueue(Q1.dequeue());
			for(j=i+1;j<size;j++)
				if(order[i]<order[j])
					order[j]--;
			flag = 1;
		}
		else
		{
			for(j=0;j<order[i];j++)
				Q1.enqueue(Q2.dequeue());
			Q3.enqueue(Q2.dequeue());
			while(!Q2.isEmpty())
				Q1.enqueue(Q2.dequeue());
			for(j=i+1;j<size;j++)
				if(order[i]<order[j])
					order[j]--;
			flag = 0;
		}
	}
	while(!Q3.isEmpty())
		Q1.enqueue(Q3.dequeue());
	cout<<"The new queue is : \n";
	while(!Q1.isEmpty())
		cout<<Q1.dequeue()<<" ";
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
 