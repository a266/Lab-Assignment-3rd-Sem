#include<iostream>
using namespace std;

class Time {
    int hours;
    int minutes;
    
    public :

        Time() {
            hours = 0;
            minutes = 0;
        }

        Time(const Time &t) {
            hours = t.hours;
            minutes = t.minutes;
        }

        void setTime(int h, int m) {
            hours = h;
            minutes = m;
        }

        void showTime() {
            cout << "hours : ";
            cout << hours;
            cout << endl;
            cout << "minutes : ";
            cout << minutes;
            cout << endl;
        }

        Time add(const Time t) {

            Time temp;

            temp.hours = hours + t.hours;
            temp.minutes = minutes + t.minutes;
            if(temp.minutes>=60){
            	int r=temp.minutes%60;
            	int d=temp.minutes/60;
            	temp.hours+=d;
            	temp.hours=r;
			}

            return temp;
    	}
    	
    	};

int main() {

    int h;
    int m;

    cout << "Enter hours in first object : ";
    cin >> h;
    cout << "Enter minutes in first object : ";
    cin >> m;
    Time first;
    first.setTime(h, m);

    cout << "Enter hours in second object : ";
    cin >> h;
    cout << "Enter minutes in second object : ";
    cin >> m;
    Time second;
    second.setTime(h, m);

    Time third = first.add(second);

    // displaying objects

    cout << "First object :-" << endl;
    first.showTime();
    cout << endl;

    cout << "Second object :-" << endl;
    second.showTime();
    cout << endl;

    cout << "Third object :-" << endl;
    third.showTime();
   	cout << endl;

    return 0;
} 
