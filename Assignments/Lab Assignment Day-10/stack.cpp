#include<stdio.h>
#define SIZE 50
using namespace std;

class Stack
{
	int arr[SIZE];
	int top;
	public:
			Stack()
			{
				top=-1;
			}
			
			void push(int data)
			{
				if(!isfull())
					arr[++top]=data;
				else
					throw "overflow";
			}
			
			int pop()
			{
				if(!isempty())
					return arr[top--];
				else
					throw "underflow";
			}
			
			int peek()
			{
				if(!isempty())
					return arr[top];
				else
					throw "underflow";
			}
			
			bool isfull()
			{
				return top == SIZE-1;
			}
			
			bool isempty()
			{
				return top == -1;
			}
			
};

