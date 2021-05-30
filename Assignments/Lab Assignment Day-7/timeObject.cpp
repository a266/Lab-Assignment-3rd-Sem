#include<iostream>
#include<conio.h>

class time
{
   private:
	int hours;
	int minutes;

   public:

	void settime(int h, int m)

	{

		hours=h; minutes=m;

	}

	time sum(time);

	void showtime();

};



time time::sum(time TM)

{

	time t;

	t.minutes = minutes + TM.minutes;

	t.hours=t.minutes/60;

	t.minutes=t.minutes%60;

	t.hours += hours + TM.hours;

	return t;

}



void time::showtime()

{

	cout<<hours<<" hours and "<<minutes<<" minutes"<<endl;

}





int main()

{

	time T1,T2,T3;

	T1.settime(2,45);

	T2.settime(3,30);

	T3=T1.sum(T2);



	cout<<"\n Time 1 : ";T1.showtime();

	cout<<"\n Time 2 : ";T2.showtime();

	cout<<"\n Time 3 : ";T3.showtime();



	getch();

	return 0;

}


