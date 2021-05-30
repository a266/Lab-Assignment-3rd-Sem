#include<iostream>
#include<string.h>
#include<math.h>
#include "stack.cpp"
using namespace std;


int main()
{
	Stack s1;
	int i,a,b,c,x,l,k;
	char temp;
	char input[100];
	cout<<"Enter a valid prefix expression: ";
	cin>>input;
	l=strlen(input);
	for(k=0;k<(l/2);k++)
	{
		temp=input[k];
		input[k]=input[l-k-1];
		input[l-k-1]=temp;
	}
//	cout<<input<<endl;
	
	while(input[i]!='\0')
	{
		if(input[i]>='0' && input[i]<='9')
		{
			x=input[i]-48;
			s1.push(x);
		}
		else if(input[i]=='+' || input[i]=='-' || input[i]=='*' || input[i]=='/' || input[i]=='%' || input[i]=='^')
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
						c=a-b;
						s1.push(c);
						break;
				case '*':
						c=b*a;
						s1.push(c);
						break;
				case '/':
						c=a/b;
						s1.push(c);
						break;
				case '%':
						c=b%a;
						s1.push(c);
						break;
				case '^':
						c=pow(a,b);
						s1.push(c);
						break;
			}
		}
		i++;
	}
	cout<<"Answer is: "<<s1.peek()<<endl;
	return 0;
}
