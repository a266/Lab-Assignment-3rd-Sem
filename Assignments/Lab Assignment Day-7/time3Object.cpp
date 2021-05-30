#include<iostream>
#include<stdlib.h>
using namespace std;
class time{
	public:
 		int hour;
 		int min;
 	void in(){
  		cout<<"enter hour ";
  		cin>>hour;
  		cout<<"enter minute ";
  		cin>>min;  
 }
 void show(){
  	cout<<hour<<" hour "<<min<<" minutes"<<endl;
 }
 void setTime(int h,int m){
  	hour=h;
  	min=m;
 }
 
};
time add(time t,time r){
 	time w;
 	w.min=t.min+r.min;
 	w.hour=t.hour+r.hour;
 	if(w.min>=60){
  	int g=w.min%60;
  	int d=w.min/60;
  	w.hour+=d;
  	w.min=g;
 }
	return w;
}
int main(void){
 	time t,T,m;
 	t.in();
 	t.show();
 	T.in();
 	T.show();
 	m=add(t,T);
 	m.show(); 
 	m.setTime(4,45);
 	m.show();
 	return 0;
}
