#include <bits/stdc++.h>
using namespace std;
 
bool isPalindromeRec(char str[], int s, int e)
{
    //Single character, return true
    if (s == e)
    {
       return true;
    }
    //If first and last characters do not match
    //Return false
    if (str[s] != str[e])
    {
       return false;
    }
    //If they are same, recursion for remaining 
    if (s < e+1)
    {
       return isPalindromeRec(str, s+1, e-1);
    }  
    //If it reaches end, return true
    return true;
}
 
bool isPalindrome(char str[])
{
   int n = strlen(str);
   //empty string is palindrome
   if (n == 0)
   {
     return true;
   }
   //Else, call recursive function
   return isPalindromeRec(str, 0, n-1);
}
 
// Main Function
int main()
{
    char str[] = "racecar";
    if (isPalindrome(str))
    {
      cout<<"Given input string is palindrome"<<endl;;
    }
    else
    {
       cout<<"Input string is not palindrome"<<endl;
    }
    return 0;
}
