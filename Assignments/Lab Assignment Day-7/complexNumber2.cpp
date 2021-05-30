#include<iostream>
using namespace std;
class complex{
	int real;
	int img;
	public:
		complex()
		{
			real=0;
			img=0;
		}
		complex(int a,int b)
		{
			real=a;
			img=b;
		}
		complex(const complex &c)
		{
			real=c.real;
			img=c.img;
		}
		void set(int a,int b)
		{
			real=a;
			img=b;
		}
		void display()
		{
			cout<<real<<"+ i"<<img<<endl;
		}
		complex sum(complex c)
		{
			complex temp;
			temp.real=real+c.real;
			temp.img=img+c.img;
			return temp;
		}
};
int main()
{
	int a,b;
	cout<<"Enter the value of first class:"<<endl;
	cin>>a>>b;
	int x,y;
	cout<<"Enter the value of second class:"<<endl;
	cin>>x>>y;
	complex c1,c2(a,b);
	complex c3;
	c3.set(x,y);
	c1.display();
	c2.display();
	c3.display();
	complex c5=c2.sum(c3);
	c5.display();

}
