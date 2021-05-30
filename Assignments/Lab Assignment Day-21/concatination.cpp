#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	char *s1=(char*)malloc(100*sizeof(char));
	char *s2=(char*)malloc(100*sizeof(char));
	int n1,n2;
	cout<<"Enter the size of String1: ";
	cin>>n1;
	cout<<"Enter the size of String2: ";
	cin>>n2;
	cout<<"Enter first string: ";
	for(int i=0 ; i<n1 ; ++i)
        cin>>s1[i];
    cout<<"Enter second string: ";
    for(int i=0 ; i<n2 ; ++i)
        cin>>s2[i];
    
	for(int i=n1 ; i<n1+n2 ; ++i)
        s1[i]=s2[i-n2];
        
    s1=(char*)realloc(s1 , (n1+n2)*sizeof(char));
    for(int i=0 ; i<n1+n2 ; ++i)
        cout<<s1[i];
        
    free(s1);
    free(s2);
}
