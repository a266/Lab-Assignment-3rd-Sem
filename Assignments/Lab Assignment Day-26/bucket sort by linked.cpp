#include<iostream>
#include<math.h>
#include"singly(float) linked list.cpp"
using namespace std;
void in(float a[],int n){
	int i;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
}
void show(float a[],int n){
		int i;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl<<endl;
}
class sort{
	public:
	float getmin(float a[],int n){
		float m=a[0];
		for(int i=1;i<n;i++){
			if(m>a[i])
				m=a[i];
		}
		return m;
	}
	int count_no_after_point(float n){
		int i=0;
		float N=n;
		while(N<1){
			N*=10;
			i++;
		}
		return i;
	}
	void bucket(float a[],int n){
		int step=1;
		int digit,p,di=10;
		float min=getmin(a,n);
		//cout<<min<<endl;
		int d=count_no_after_point(min);
		
		p=pow(10,d);
		while(d--){
			//cout<<d<<endl;
			//show(a,n);
			linked_list l[10];
			for(int i=0;i<n;i++){
				digit=a[i]*p;
				digit%=10;
				l[digit].insert_sorted(a[i]);
			}
			int j=0;
			for(int i=0;i<10;i++){
				while(!l[i].underflow())
					a[j++]=l[i].pop_front();
			}
			p/=10;
			di*=10;
			cout<<"Step "<<step++<<endl;
			show(a,n);
		}
	}
};
int main(void){
	int n;
	cout<<"Enter size-";
	cin>>n;
	float a[n];
	in(a,n);
	show(a,n);
	sort o;
	o.bucket(a,n);
	cout<<endl<<endl<<"FINAL RESULT,.........."<<endl;
	show(a,n);
}
