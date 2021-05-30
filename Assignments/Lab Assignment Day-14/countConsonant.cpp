#include<iostream>
#include<sstream>
using namespace std;

int consonant(char t){
	if((t>='a' && t<='z')||(t>='A' && t<='Z'))
	{
		if(t == 'A' || t == 'E' ||t == 'I' ||t == 'O' ||t == 'U'||
		t == 'a' || t == 'e' ||t == 'i' ||t == 'o' ||t == 'u'){
		
			return 0;
	}
		else
		{
			return 1;
		}
	}
	else
		return 0;
}

int consonantcount(string str, int n){
   	if (n == 1){
      	return consonant(str[0]);
   	}
   	return consonantcount(str, n - 1) + consonant(str[n-1]);
}

int main()
{
	string s;
	cout<<"Enter a String:";
	getline(cin,s);
	cout<<"Total Consonant is: "<< consonantcount(s,s.length());
	return 0;
}
