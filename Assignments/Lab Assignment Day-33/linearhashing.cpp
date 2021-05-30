#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define size 10


int table[size];


int hash(int key){
	return (key%size);
}

void insert(int key){
	int index=hash(key);
	if(table[index]<0){
		table[index]=key;
		return;
	}
	for(int i=1;i<size;i++){
		int newIndex=(index+i)%size;
		if(table[newIndex]<0){
			table[newIndex]=key;
			return;
		}
	}
	cout<<"Hash table is full"<<endl;
}

void search(int key){
	int index=hash(key);
	for(int i=0;i<size;i++){
		int newIndex=(index+i)%size;
		if(table[newIndex]==key){
			cout<<"Key found at position "<<newIndex<<endl;
			return;
		}
		if(table[newIndex]==-1){
			cout<<"Not Found!!"<<endl;
			return;
		}
	}
	cout<<"Element is not present!! "<<endl;
	return;
}

void remove(int key){
	int index=hash(key);
	for(int i=0;i<size;i++){
		int newIndex=(index+i)%size;
		if(table[newIndex]==key){
			cout<<"Element deleted "<<endl;
			table[newIndex]=-2;
			return;
		}
		if(table[newIndex]==-1){
			cout<<"Element not found!! "<<endl;
			return;
		}
	}
	cout<<"Element is not present!! "<<endl;
	return;
}

void display()
{
    for(int i=0;i<size;i++)
    {
      	cout<<"Table index "<<i<<": ";
      	cout<<table[i]<<endl;
    }
}

int main(){
	int x;
	memset(table,-1,sizeof(table));
	do
    {
    	cout<<"------LINEAR PROBING-------"<<endl;
        cout<<"1.insert element"<<endl;
		cout<<"2.search element"<<endl;
		cout<<"3.delete elelement"<<endl;
		cout<<"4.display"<<endl;
		cout<<"0.Exit"<<endl;
        int n;
        cin>>n;
        switch(n)
        {
           	case 1:
           		system("CLS");
               	cout<<"Enter the item";
                cin>>x;
                insert(x);
                break;
            case 2:
            	system("CLS");
              	cout<<"Enter the element which you want to search: ";
              	cin>>x;
              	search(x);
              	break;
            case 3:
            	system("CLS");
            	cout<<"Enter the element which you want to delete: ";
                cin>>x;
				remove(x);
                break;
            case 4:
            	system("CLS");
            	display();
                break;
            case 0:
                cout<<"Good Bye!!!!!!!";
				break;
            default:cout<<"Wrong Selection!!! please try again!!!"<<endl;
        }
    }
	while(x!=0);
}
