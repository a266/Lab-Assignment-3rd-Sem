#include<iostream>
using namespace std;
int l=0;
int comp=0;


class arr{
	public:
    int num;
    int ind;
};


void merge(arr a[],int left,int mid,int right)
{
	int i=left,j=mid+1,k=left;
	arr x[right];
	while(i<=mid && j<=right&& ++comp)
	{
		if(a[i].num<=a[j].num)
		{
			x[k].num=a[i].num;
            x[k].ind=a[i].ind;
            k++;
            i++;
		}
		else
		{
			x[k].num=a[j].num;
            x[k].ind=a[j].ind;
            k++;
            j++;
		}
	}
	while(i<=mid)
	{
		x[k].num=a[i].num;
        x[k].ind=a[i].ind;
        k++;
        i++;
	}
	while(j<=right)
	{
		x[k].num=a[j].num;
        x[k].ind=a[j].ind;
        k++;
        j++;
	}
	for(int i=left;i<=right;i++)
	{
		a[i].num=x[i].num;
        a[i].ind=x[i].ind;
	}

}


void mergesort(arr a[],int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(a,left,mid);
		mergesort(a,mid+1,right);
		merge(a,left,mid,right);
		cout<<"pass:"<<++l<<"\n";
		for(int i=left;i<=right;i++)
		{
			cout<<a[i].num<<" ";
		}
    	cout<<"\n";
    	for(int i=left;i<=right;i++)
    	{
     		cout<<a[i].ind<<" ";
    	}
		cout<<"\n";
	}
}


int main()
{
	int m;
	cout<<"enter the size of the 1st array:";
	cin>>m;
	arr a[m];
	cout<<"enter the elements of the 1st array:";
	for(int i=0;i<m;i++)
	{
		cin>>a[i].num;
        a[i].ind=i;
	}
	int v=0;
	int w=m-1;
	mergesort(a,v,w);
	cout<<"sorted array:";
	for(int i=0;i<m;i++)
	{
		cout<<a[i].num<<" ";
	}
    cout<<"\n";
    for(int i=0;i<m;i++)
    {
        cout<<a[i].ind<<" ";
    }
	cout<<"\n";
	cout<<"no of comparison:"<<comp;
}
