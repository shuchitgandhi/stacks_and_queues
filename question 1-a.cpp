#include<iostream>
#define size 50
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
int main()
{
	StackA S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(5);
	cout<<"The stack is : \n";
	while(!S.isEmpty())
		cout<<S.pop()<<" ";
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