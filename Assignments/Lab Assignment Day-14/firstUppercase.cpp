#include<iostream>
#include<sstream>
using namespace std;

char first(string str, int i=0) 
{ 
    if (str[i] == '\0') 
         return 0; 
    if (isupper(str[i]))  
            return str[i]; 
    return first(str, i+1); 
} 



int main() 
{ 
    string s;
	cout<<"Enter a String:";
	getline(cin,s);
    char res = first(s);
    if (res == 0) 
        cout << "No uppercase letter"; 
    else
        cout << res << "\n"; 
    return 0; 
} 
