#include<iostream>
#include<vector>

using namespace std;

class Graph{
    private:
       int n;
       int e;
       vector<vector<int>> adj;
    public:
      Graph(int V,int E)
      {
        n=V;
        e=E;
        adj.resize(n+1,vector<int> (n+1,0));
      }
      void insert(int u,int v);
      void display();
      void Delete(int u,int v);
      void search(int u,int v);
};
void Graph::insert(int u,int v)
{
    if(u<n && v<<n){
        adj[u][v]=1;
        adj[v][u]=1;
    }else{
        cout<<"Invalid range of edges"<<endl;
    }
}
void Graph::display()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<e;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
}
void Graph::Delete(int u,int v)
{
    if(u<n && v<<n){
        cout<<"Deleted edges: "<<u<<" "<<v<<endl;
        adj[u][v]=0;
        adj[v][u]=0;
    }else{
        cout<<"Invalid range of edges"<<endl;
    }
   
}
void Graph::search(int u,int v)
{
    if(u<n && v<<n)
    {
        if(adj[u][v]==1)
        {
            cout<<"Edge is Found"<<endl;
        }
        else
        {
            cout<<"Edge is not found"<<endl;
        }
    }
    else{
        cout<<"Give proper range of edges"<<endl;
    }

}

int main()
{
    Graph g(4,4);
    int flag=1;
    while(flag)
    {
        cout<<"1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit";
        int choice,u,v;
        cout<<"Enter choice :"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1 :
            cout<<"Enter the edge"<<endl;
            cin>>u>>v;
            g.insert(u,v);
            break;
        
        case 2:
            g.display();
            break;
        case 3:
            cout<<"Enter the edge"<<endl;
            cin>>u>>v;
            g.Delete(u,v);
            break;
        case 4:
             cout<<"Enter the edge to be searched"<<endl;
             cin>>u>>v;
             g.search(u,v);
             break;
        case 5:
             cout<<"Exit"<<endl;
             flag=0;
        }
    }
}