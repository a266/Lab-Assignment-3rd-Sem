#include<iostream>
#include<cstring>
using namespace std;

//#define V 5

//int G[V][V]={
//		{0,4,0,5,2},
//		{4,0,1,3,0},
//		{0,1,0,8,0},
//		{5,3,8,0,2},
//		{2,0,0,2,0}
//	};

int main(){
	

	int V;
	cout<<"Enter number of vertices"<<endl;
    cin>>V;
    int G[V][V];
    cout<<"Enter adjacency Matrix: "<<endl;
    for(int i=0 ; i<V ; ++i)
    {
        for(int j=0 ; j<V ; ++j)
        	cin>>G[i][j];
    }
    
	
	int v_array[V];
	
	
	memset(v_array,false,sizeof(v_array));
	
	
	v_array[0]=true;
	
	
	cout<<"EDGE : WEIGHT\n";
	int n_edge=0;
	while(n_edge<V-1){
		
		
		int min=INT_MAX;
		
		int r=0,c=0;
		
		
		for(int i=0;i<V;i++){
			
			if(v_array[i]){
				
				
				for(int j=0;j<V;j++){
					if(min>G[i][j]){
						if(!v_array[j]&& G[i][j]){
							min=G[i][j];
							r=i;
							c=j;
						}
					}
				}
			}
		}
		
		
		cout<<" "<<r<<"-"<<c<<":"<<G[r][c];
		cout<<endl;
		v_array[c]=true;
		n_edge++;
	}
	return 0;
}
