#include<iostream>
#define max 30

using namespace std;

class Stacks{
    
    public:

    int arr[max];
    int top;
    
    Stacks(){
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

    void push(int item){
        top++;
        arr[top] = item;
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
                cout << arr[i] << " ";
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
            int x = arr[top];
            top--;
            return x;
        }
        else
        
            cout << "Stack is Empty" << endl;
            
    }       
};

int main(){

    int n , a[30];
    
    Stacks s1, s2;

    cout << "enter the size of the array" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0)
        {
            s1.push(a[i]);
        }
        else
        {
            s2.push(a[i]);
        }
        
    }
    cout << "\nThe even stack is" << endl;
    s1.display();

    cout << "\nThe odd stack is" << endl;
    s2.display();

    return 0;
    
}
