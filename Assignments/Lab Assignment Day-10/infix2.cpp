#include <stdlib.h>
#include <string.h>
#include<iostream>

#define max 4

using namespace std;

class Stack{
    
    public:

    char arr[max];
    int top;
    
    Stack(){
        top = -1;
    }


    bool isEmpty(){
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }    

    bool isFull(){
        if (top == max - 1)
        
            return true;
        
        else
        
            return false;
           
    }    

    void push(char item){
        if (top == max - 1)
        {
            cout << "stack is full";
        }
        
        else
        {
            top++;
            arr[top] = item;
        }
        
        
    }

    int peek(){
        if (!isEmpty())
    
            return arr[top];
    
        else
    
            cout << "Stack is Empty" << endl;
               
    }

    void display(){
        if (!isEmpty())
        {
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << endl;
            }
        }

        else
        {
            cout << "The Stack is Empty" << endl;
        }
        
    }
        
    int pop(){
        if (!isEmpty())
        {
            char x = arr[top];
            top--;
            return x;
        }
        else
        
            cout << "Stack is Empty" << endl;
        
    }       
};


int precendence(char c){

    if (c == '*' || c == '/')
    {
        return 1;
    }

    else if (c == '+' || c == '-')
    {
        return 0;
    }

    else
    {
        return -222;
    } 
}

int main(){
    
    Stack st;
    st.push('$');
    string s1, s2;

    cout << "Enter the string" << endl;

    cin >> s1;

    int l = s1.length();

    for(int i = 0; i < l; i++){

        if ((s1[i] >= 'a' && s1[i] <= 'z') || (s1[i] >= 'A' && s1[i] <= 'Z'))
        {
            s2 += s1[i];
        }

        else if (s1[i] == '(')
        {
            st.push('(');
        }

        else if (s1[i] == ')')
        {
            while (st.peek() != -1 && st.peek() != '(')
            {
                char ch = st.peek();
                st.pop();
                s2 += ch;
            }

            if (st.peek() == '(')
            {
                char ch = st.peek();
                st.pop();
            }   
        }

        else
        {
            while (st.peek() != '$' && precendence(s1[i]) <= precendence(st.peek()))
            {
                char ch = st.peek();
                st.pop();
                s2 += ch; 
            }
            st.push(s1[i]);           
        }       
    }

    while (st.peek() != '$')
    {
        char ch = st.peek();
        st.pop();
        s2 += ch;
    }

    cout << "The postfix Expression is" << endl;


    cout << s2 <<endl;

    return 0;
}
