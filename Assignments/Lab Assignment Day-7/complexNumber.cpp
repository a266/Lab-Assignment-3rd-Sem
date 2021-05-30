#include<iostream>
#include<conio.h>

class complex
{
   private:
	float x;
	float y;
   public:
	void set(float real, float img)
	{
		x=real; y=img;
	}
	complex sum(complex);
	void disp();
};

complex complex::sum(complex C)
{
	complex t;
	t.x = x + C.x;
	t.y = y + C.y;
	return t;
}

void complex::disp()
{
	cout <<x<<" + j"<<y;
}

int main()
{
	complex C1,C2,C3;
	C1.set(2.5,7.1);
	C2.set(4.2,5.5);
	C3=C1.sum(C2);
	cout<<"\n complex Number 1 = ";C1.disp();
	cout<<"\n complex Number 2 = ";C2.disp();
	cout<<"\n complex Number 3 = ";C3.disp();
	getch();
	return 0;
}
