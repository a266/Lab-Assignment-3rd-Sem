#include <bits/stdc++.h>
#define MAX 1000 
using namespace std; 


bool isPalindromeRec(char s[],int x, int y) 
{  
    if (x == y) 
    return true;
    if (s[x] != s[y]) 
    return false; 
    if (x < y + 1) 
    return isPalindromeRec(s, x + 1, y - 1); 
    return true;
} 
  
bool isPalindrome(char s[]) 
{ 
    int n = strlen(s);  
    if (n == 0) 
        return true;
    return isPalindromeRec(s, 0, n - 1); 
} 
  
 
int main() 
{ 
    char s[MAX];
	cout<<"Enter string: ";
	cin>>s; 
    if (isPalindrome(s)) 
    cout << "Yes Pallindrome"; 
    else
    cout << "Not Pallindrme"; 
  
    return 0; 
}
