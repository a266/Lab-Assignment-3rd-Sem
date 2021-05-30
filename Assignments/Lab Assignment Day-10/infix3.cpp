#include<iostream>
#include<string>
#define MAX 20
class Stack
{
	public:
	char arr[MAX];
	int top;
	public:
	Stack()
	{
		top=-1;
	}
	void push(char item)
	{
		if(!isFull())
		{
			top++;
			arr[top]=item;
		}
	}
	char pop()
	{
		if(!isEmpty())
		{
			char x=arr[top];
			top=top-1;
			return x;
		}
	}
	int peek()
	{
		if(!isEmpty())
		{
			return(arr[top]);
		}
	}
	int isFull()
	{
		if(top==MAX-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int isEmpty()
	{
		if(top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	int display()
	{
		if(!isEmpty())
		{
			for(int i=top;i>=0;i--)
			{
				cout<<(char)arr[i]<<" ";
			}
		}
	}
	
};
int isOperator(char symbol)
{
	if(symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-'||symbol=='^')
	{
		return 1;
	}
	else{
		return 0;
	}
}
int isDigit(char symbol)
{
	if(symbol>='0' && symbol<='9')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isAlpha(char symbol)
{
	if(symbol>='A' && symbol<='Z')
	{
		return 1;
	}
	else if(symbol>='a' && symbol<='z')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isOperand(char symbol)
{
	if(isAlpha(symbol)||isDigit(symbol))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int precedence(char symbol)
{
	if(symbol=='^')
	{
		return 3;
	}
	if(symbol=='*'|| symbol=='/')
	{
		return 2;
	}
	if(symbol=='+'|| symbol=='-')
	{
		return 1;
	}	
}

int main()
{
	Stack s1;
	string  s;
	cout<<"enter the infix expression:";
	cin>>s;
	int l=s.length();
	char ch;
	string res="";
	for(int i=0;i<l;i++)
	{
		ch=s[i];
		if(isDigit(ch)||isAlpha(ch))
		{
			res+=ch;
		}
		else if(ch=='(')
		{
			s1.push(ch);
			
		}
		else if(isOperator(ch))
		{
			if(s1.isEmpty())
			{
				s1.push(ch);
			}
			else if(s1.peek()=='(')
			{
				s1.push(ch);
			}
			
			else if(precedence(ch)>precedence(s1.peek()))
			{
				s1.push(ch);
			}
			else if(precedence(ch)==precedence(s1.peek()))
			{
				res+=s1.pop();
				s1.push(ch);
			}
			else
			{
				while(precedence(ch)<precedence(s1.peek()))
				{
					res+=s1.pop();
					s1.push(ch);
				}
			}
		}
		else if(ch==')')
		{
			while(s1.peek()!='(')
			{
				res+=s1.pop();
			}
			s1.pop();
		}
		s1.display();
		cout<<"\n";
	}
	while(!s1.isEmpty())
	{
		char c=s1.pop();
		res+=c;
	}
	res+='\0';
	s1.display();
	cout<<"\n";
	cout<<"postfix exp:"<<res;
	return 0;
}
