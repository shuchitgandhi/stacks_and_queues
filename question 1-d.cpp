#include<iostream>
#define size 100
using namespace std;
class StackA
{
	private:
		int stack[size];
		int top;
	public :
		StackA();
		void push(int);
		int pop();
		bool isEmpty();
		bool isFilled();
};

class QueueByStack
{
	private:
		StackA S1, S2;
	public:
		QueueByStack();
		void enqueue(int);
		int dequeue();
		bool isEmpty();
};
int main()
{
	QueueByStack Q;
	Q.enqueue(1);Q.enqueue(2);Q.enqueue(3);Q.enqueue(4);Q.enqueue(5);
	cout<<"The queue is : \n";
	while(!Q.isEmpty())
		cout<<Q.dequeue()<<" ";
	return 0;
}
 
 
StackA::StackA()
{
	top = -1;
}

void StackA::push(int x)
{
	if(top==size-1)
		cout<<"OVERFLOW";
	else
		stack[++top] = x;
}

int StackA::pop()
{
	if(top==-1)
	{
		cout<<"UNDERFLOW";
		return -1;		
	}
	else
		return stack[top--];
}

bool StackA::isEmpty()
{
	if(top==-1)
		return true;
	else
		return false;
}

bool StackA::isFilled()
{
	if(top==size-1)
		return true;
	else
		return false;
}
 
 
QueueByStack::QueueByStack(){}

void QueueByStack::enqueue(int x)
{
	if(S2.isFilled() || S1.isFilled())
		cout<<"OVERFLOW";
	else
	{
		if(S1.isEmpty())
		while(!S2.isEmpty())
			S1.push(S2.pop());
		S1.push(x);
	}
}

int QueueByStack::dequeue()
{
	if(S2.isEmpty() && S1.isEmpty())
	{
		cout<<"UNDERFLOW";
		return -1;
	}
	else
	{
		if(S2.isEmpty())
		while(!S1.isEmpty())
			S2.push(S1.pop());
		return S2.pop();
	}
}

bool QueueByStack::isEmpty()
{
	if(S1.isEmpty() && S2.isEmpty())
		return true;
	else
		return false;
}
 