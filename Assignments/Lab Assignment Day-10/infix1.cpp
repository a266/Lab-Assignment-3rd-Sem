#include<stdio.h>
#include<iostream>
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
					arr[top++]=data;
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

int findprecedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
				return 1;
		case '*':
		case '/':
		case '%':
				return 2;
		case '^':
				return 3 ;
	}
	return 0;
}

int main()
{
	int i,j=0;
	Stack s1;
	char ch;
	char infix[100],postfix[100];
	
	
	cout<<"Enter infix expression: "<<endl;
	cin>>infix;
	i=0;
	while(infix[i]!='\0')
	
	{
	
	infix[i+1]='\0';
	infix[i--]=')';
	}
	while(i>0)
	{
		infix[i]=infix[i-1];
		i--;
		
	}
	infix[i]='(';
	//cout<<infix<<endl;
	
	i=0;
	while(infix[i]!='\0')
	{
		if(infix[i]=='(')
		{
			s1.push(infix[i]);
		}
		
		else if(infix[i]>='a' && infix[i]<='z')
		{
			postfix[j++]=infix[i];
		}
		
		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/')
		{
			while(s1.peek()=='+' || s1.peek()=='-' ||s1.peek()=='*' ||s1.peek()=='/')
			{
				if(findprecedence(s1.peek())>=findprecedence(infix[i]))
				{
					postfix[j++]=s1.pop();
				}
				else
						break;
			}
			s1.push(infix[i]);
		}
		else if(infix[i]==')')
		{
			while((ch=s1.pop())!='(')
			{
				postfix[j++]=ch;
			}	
		}
		i++;
		cout<<postfix<<endl;
	}
	
	postfix[j]='\0';
	
	cout<<postfix<<endl;
	
	return 0;
}
