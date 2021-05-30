#include<iostream>

using namespace std;

void odd();
void even();

int n = 1;

void odd(){
    if (n > 10) 
    {
        return;
    }

    else
    {
        cout << n + 1 << " ";
        n++;
        even();
    }
}

void even(){
    if (n > 10)
    {
        return;
    }
    else
    {
        cout << n - 1 << " ";
        n++;
        odd();
    }
}

int main(){
    odd();
    return 0;
}
