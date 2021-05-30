#include <iostream>
using namespace std; 
 
int rev(int n, int temp) 
{
    if (n == 0) 
        return temp;  
    temp = (temp * 10) + (n % 10);   
    return rev(n / 10, temp); 
} 
   
int main() 
{
    int n;
    cout<<"Enter a digit to check if a number is pallindrome or not: ";
	cin>>n; 
    int temp = rev(n, 0);
    if (temp == n) 
        cout << "yes pallindrome" << endl; 
    else
        cout << "not pallindrome" << endl; 
    return 0; 
} 
