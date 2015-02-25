#include<iostream>
#define size 100
using namespace std;
class QueueA
{
	private:
		int queue[size];
		int head, tail;
	public:
		QueueA();
		void enqueue(int);
		int dequeue();
		bool isEmpty();
		bool isFilled();
};

class StackByQueue
{
	private:
		QueueA Q1, Q2;
		int ele;
	public :
		StackByQueue();
		void push(int);
		int pop();
		bool isEmpty();	
};
int main()
{
	StackByQueue S;
	S.push(1);S.push(2);S.push(3);S.push(4);S.push(5);
	cout<<"The stack is : \n";
	while(!S.isEmpty())
		cout<<S.pop()<<" ";
	return 0;
}
QueueA::QueueA()
{
	head =-1;
	tail = 0;
}

void QueueA::enqueue(int x)
{
	if(head==-1 && tail==size)
		cout<<"OVERFLOW";
	else
		queue[tail++] = x;
}

int QueueA::dequeue()
{
	if(head==tail-1)
	{
		cout<<"UNDERFLOW";
		return -1;
	}	
	else
	{
		return queue[++head];
	}
}

bool QueueA::isEmpty()
{
	if(head==tail-1)
		return true;
	else
		return false;
}

bool QueueA::isFilled()
{
	if(head==-1 && tail==size)
		return true;
	else
		return false;
}
StackByQueue::StackByQueue()
{
	ele = 0;
}

void StackByQueue::push(int x)
{
	if(Q1.isFilled() || Q2.isFilled())
	{
		cout<<"OVERFLOW";
	}
	else
	{
		 if(!Q2.isEmpty())
		 	Q2.enqueue(x);
		 else
		 	Q1.enqueue(x);
		 ele++;
	}
}

int StackByQueue::pop()
{
	if(ele==0)
	{
		cout<<"UNDERFLOW";
	}
	else
	{
		if(!Q1.isEmpty())
		{
			for(int i=0;i<ele-1;i++)
				Q2.enqueue(Q1.dequeue());
			ele--;
			return Q1.dequeue();
			
		}
		else
		{
			for(int i=0;i<ele-1;i++)
				Q1.enqueue(Q2.dequeue());
			ele--;
			return Q2.dequeue();
		}
	}
}

bool StackByQueue::isEmpty()
{
	if(ele==0)
		return true;
	else
		return false;
}
//====================================================================================