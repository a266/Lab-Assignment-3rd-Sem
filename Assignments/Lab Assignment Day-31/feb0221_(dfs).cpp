#include<iostream>
//#include "queuelink.cpp"
#include "stacklink.cpp"
using namespace std;
int v;
int graph[1000][1000];
int vis[100]={0};
/*void bfs(int n)
{
      queue q;
      vis[n]=1;
      q.enqueue(n);
      while(!q.isempty())
      {
            int u=q.dequeue();
            cout<<u<<" ";
            for(int w=0 ; w<v ; ++w)
            {
                  if(graph[u][w]==1)
                  {
                        if(vis[w]!=1)
                        {
                              vis[w]=1;
                              q.enqueue(w);
                        }
                  }
            }
      }

}*/
void dfs(int n)
{
    stack st;
    st.push(n);
    vis[n]=1;
    while(!st.isempty())
    {
        int u=st.pop();
        cout<<u<<" ";
        for(int w=0 ; w<v ; ++w)
        {
            if(graph[u][w]==1)
            {
                if(vis[w]!=1)
                {
                    vis[w]=1;
                    st.push(w);
                }
            }
        }
    }

}
void dfsrecur(int n)
{

}
int main()
{

    cout<<"Enter number of vertices"<<endl;
    cin>>v;
    for(int i=0 ; i<v ; ++i)
    {
          for(int j=0 ; j<v ; ++j)
            cin>>graph[i][j];
    }

    dfs(0);

}
