//infix to prefix

#include<iostream>
#include<stdio.h>
#include<string.h>
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


int findprecedence(char ch)
{
	switch(ch)
	{
		case '+':
		case '-':
				return 1;
		case '*':
		case '/':
				return 2;
	}
	return 0;
}

int main()
{
	Stack s1;
	int i,j=0,k,l;
	char ch,temp;
	char infix[100],postfix[100],prefix[100];
	
	cout<<"Enter infix Expression"<<endl;
	cin>>infix;
	i=0;
	while(infix[i++]!='\0');	//it take me to the end of array
	
	infix[i+1]='\0';
	infix[i--]=')';
	while(i>0)
	{
		infix[i]=infix[i-1];
		i--;
	}
	infix[i]='(';
	
//	cout<<infix<<endl;
	
	l=strlen(infix);
	for(k=0;k<(l/2);k++)
	{
		temp=infix[k];
		infix[k]=infix[l-k-1];
		infix[l-k-1]=temp;
	}
	
//	cout<<infix<<endl;
	
	for(k=0;k<l;k++)
	{
		if(infix[k]=='(')
			infix[k]=')';
		else if(infix[k]==')')
			infix[k]='(';
	}
	
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
			while(s1.peek()=='+' || s1.peek()=='-' || s1.peek()=='*' || s1.peek()=='/')
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
	}
	postfix[j]='\0';
	l=strlen(postfix);
	for(k=0;k<l;k++)
	{
		prefix[k]=postfix[l-k-1];
	}
	prefix[k]='\0';
	cout<<"Prefix format: "<<prefix<<endl;
	return 0;
}
