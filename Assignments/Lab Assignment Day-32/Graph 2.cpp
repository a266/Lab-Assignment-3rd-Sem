#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<stdlib.h>
using namespace std;
int find(vector<char> s,char a){
	for(int i=0;i<s.size();i++){
		if(s[i]==a)
			return i;
	}
	return -1;
}
class graph{
	int **G;
	vector<char> vset;
	int v;
	public:
		graph(int n){
			v=n;
			G=(int**)malloc(n*sizeof(int*));
		}
		void addvertex(char k){
			int i;
			int  *a=(int*)malloc(v*sizeof(int));
			int s=vset.size();
			if(s==v){
				cout<<"overflow.."<<endl;
				return;
			}
			vset.push_back(k);
			if(s==0){
				*(a+0)=0;
		}
			if(s>0){
				for(i=0;i<s;i++){
			//	*(G+i*(s)+s)=0;
					G[i][s]=0;
					*(a+i)=0;
				
				}
				*(a+i)=0;
			}
			*(G+s)=a;
			
	}
	void addedge(int x,int y){
		G[x][y]++;
		G[y][x]++;
	}
	void show_adj_mat(){
		cout<<"........THE ADJACENCY MATRIX............"<<endl;
		int i,j;
		int s=vset.size();
		for(i=0;i<s;i++){
			cout<<" "<<vset[i];
			
		}
		
		cout<<endl;
		for(i=0;i<s;i++){
			cout<<vset[i];
			for(j=0;j<s;j++){
				cout<<G[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<"........................................."<<endl;
	}
	void add_vertex(char a,char b){
		int x=find(vset,a);
		int y=find(vset,b);
		addedge(x,y);
	}	
	void show_vertex(){
		cout<<endl<<".................VERTEX SET................"<<endl<<'{';
		for(int i=0;i<vset.size();i++)
			cout<<" "<<vset[i]<<"";
		cout<<'}'<<endl<<"..........................................."<<endl;
	}
	void BFS(char a){
		cout<<endl<<".............BREATH FIRST SEARCH.............."<<endl;
		queue<int> q;
		int x=find(vset,a);
		bool visit[vset.size()];
		q.push(x);
		visit[x]=true;

		while(!q.empty()){
			int vertex=q.front();
			cout<<vset[vertex]<<",";
			q.pop();
			for(int i=0;i<vset.size();i++){
				if(G[x][i]!=0 && visit[i]!=true){
					q.push(i);
					visit[i]=true;
				}
					
			}
			
		}
		for(int i=0;i<vset.size();i++){
			if(visit[i]!=true){
				visit[i]=true;
				cout<<vset[i]<<",";
			}
		}
		cout<<endl<<".........................................."<<endl;
	}

	void dfs(int i,bool visited[])               //Recursive function for dfs traversal
{
		int j;
		int z=i;
		visited[i]=true;
		for(j=0;j<vset.size();j++)
			if(!visited[j]&&G[i][j]==1)
				dfs(j,visited);
		cout<<vset[z]<<" ";
}
	void DFS(char a){
		bool visited[vset.size()];
		dfs(find(vset,a),visited);
		for(int k=0;k<vset.size();k++){
			if(visited[k]!=true){
				cout<<vset[k]<<",";
				visited[k]=true;
			}
		}
	}
};
int main(void){
/*	graph a(4);
	a.addvertex('A');
	a.addvertex('B');
	a.addvertex('C');
	a.addvertex('D');
	a.add_vertex('A','D');
	a.add_vertex('A','B');
	a.show_adj_mat();
	a.show_vertex();
	a.DFS('A');8*/
	int k;
	cout<<"Enter number of maximum vertex ";
	cin>>k;
	graph a(k);
	int m=1;
	char x,y;
	while(m!=0){
		cout<<"1 to add vertex to the graph "<<endl;
		cout<<"2 to add an edge between two vertex "<<endl;
		cout<<"3 to show set of vertex "<<endl;
		cout<<"4 to show Adjacency matrix"<<endl;
		cout<<"5 for BREADH FIRST SEARCH"<<endl;
		cout<<"6 for DEPTH FIRST SEARCH"<<endl;
		cout<<"0 to close"<<endl<<"enter choice-";
		cin>>m;
		
		switch(m){
			case 1:
				cout<<"Name of the vertex-";
				cin>>x;
				a.addvertex(x);
				break;
			case 2:
				a.show_vertex();
				cout<<"Enter two vertex you want to join ";
				cin>>x>>y;
				a.add_vertex(x,y);
				break;
			case 3:
				a.show_vertex();
				break;
			case 4:
				a.show_adj_mat();
				break;
			case 5:
				cout<<"Enter what vertex you want to take as root-";
				cin>>x;
				a.BFS(x);
				break;
			case 6:
				cout<<"Enter what vertex you want to take as root-";
				cin>>x;
				a.DFS(x);
				break;				
				
	}
	}
}
