#include<iostream>
#include<math.h>
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
			
			int peep()
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


int main()
{
	Stack s1;
	int i=0,x,a,b,c;
	char input[100];
	
	cout<<"Enter a valid Postfix expression: "<<endl;
	cin>>input;
	
	
	while(input[i]!='\0')
	{
		if(input[i]>='0' && input[i]<='9')
		{
			x=input[i]-48;
			s1.push(x);					
		}
		else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' )
		{
			a=s1.pop();
			b=s1.pop();
			switch(input[i])
			{
				case '+':
						c=b+a;
						s1.push(c);
						break;
				case '-':
						c=b-a;
						s1.push(c);
						break;
				case '*':
						c=b*a;
						s1.push(c);
						break;
				case '/':
						c=b/a;
						s1.push(c);
						break;
			}
		}
		i++;	
	}
	cout<<"Answer = "<<s1.pop()<<endl;
	cout<<a<<b;
	
	return 0;
}
