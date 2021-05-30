#include<iostream>
using namespace std;

class Complex{
	int real;
	int imag;
	public:
		Complex()
		{
			real=0;
			imag=0;
			
		}
		Complex(int x,int y){
			real=x;
			imag=y;
		}
		Complex(const Complex &c){
			real=c.real;
			imag=c.imag;
		}		
		void set(int r,int i){
			real = r;
			imag = i;
		}
		void display(){
			cout<<real<<"+i"<<imag<<endl;
		}
};

int main(){
	Complex c1;
	c1.set(10,20);
	c1.display();
	Complex c2;
	c2.display();
	
	Complex c3=Complex(50,60);
	c3.display();
	
	Complex c4=Complex(c3);
	c4.display();
	
}
