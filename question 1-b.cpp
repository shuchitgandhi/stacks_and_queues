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
int main()
{
	QueueA Q;
	Q.enqueue(1);Q.enqueue(2);Q.enqueue(3);Q.enqueue(4);Q.enqueue(5);
	cout<<"The queue is : \n";
	while(!Q.isEmpty())
		cout<<Q.dequeue()<<" ";
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