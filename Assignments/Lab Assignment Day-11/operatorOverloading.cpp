#include<iostream>
using namespace std;

	class Complex{
		int real;
		int imag;
		public:
			Complex();
			Complex(int r,int i);
			Complex(const Complex &);
			void display();
			Complex operator+ (Complex);
			Complex operator- (Complex);
			Complex operator* (Complex);
			Complex operator/ (Complex);
			void operator= (Complex);
	};
	
	Complex :: Complex(){
		real=0;
		imag=0;
	}
	
	Complex :: Complex(int r,int i){
		real=r;
		imag=i;
	}
	
	Complex :: Complex(const Complex &c){
		real=c.real;
		imag=c.imag;
	}
	
	void Complex :: display(){
		if(imag>0)
			cout<<real<<"+i"<<imag<<endl;
		else
			cout<<real<<"-i"<<imag<<endl;
	}
	
	Complex Complex :: operator+ (const Complex c){
		Complex temp;
		temp.real=real+c.real;
		temp.imag=imag+c.imag;
		return temp;
	}
	
	Complex Complex :: operator- (const Complex c){
		Complex temp;
		temp.real=real-c.real;
		temp.imag=imag-c.imag;
		return temp;
	}
	
	Complex Complex :: operator* (const Complex c){
		Complex temp;
		temp.real=real*c.real - imag*c.imag;
		temp.imag=imag*c.real + real*c.imag;
		return temp;
	}
	
	void Complex :: operator=(const Complex C){
		real=C.real;
		imag=C.imag;
	}


int main()
{
	Complex c1(10,20);
	Complex c2(30,40);
	Complex c3(50,60);
	
	Complex c4,c5,c6,c7;
	c4=c1+c2+c3;
	c5=c2-c3;
	c6=c1*c2*c3;
	c7=c3;
	
	c4.display();
	c5.display();
	c6.display();
	c7.display();
	
	return 0;
}
