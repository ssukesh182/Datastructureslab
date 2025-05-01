#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Graph
{
private:
    int n;
    vector<int> *adj;

public:
    Graph(int V)
    {
        n = V;
        adj = new vector<int>[n];
        for (int i = 0; i < n; i++)
        {
            for(int j=0;i<adj[i].size();i++)
            {
                adj[i][j]=0;
            }
        }
    }
    void insert(int u, int v);
    void display();
    void Delete(int u, int v);
    void search(int u,int v);
    void TopoSort(int V);
    void dfsTraversal(int ,int [],stack<int> & ,vector<int> *);
    
};
void Graph::dfsTraversal(int node,int vis[],stack<int> &st,vector<int> *adj)
{
    vis[node]=1;
    for(auto i:adj[node])
    {
        if(!vis[node])
        {
            dfsTraversal(i,vis,st,adj);
        }
    }
    st.push(node);
}
void Graph::insert(int u, int v)
{
    if (u < n && v < n)
    {
        adj[u].push_back(v);
    }
    else
    {
        cout << "Out of Range" << endl;
    }
}
void Graph::display()
{
    for (int i = 0; i < n; i++)
    {
        cout << i << "->[";
        for (auto it : adj[i])
        {
            cout << it << ",";
        }
        cout << "]" << endl;
    }
}
void Graph::Delete(int u, int v)
{
    if (u < n && v < n)
    {
        cout << "Deleted edges: " << u << " " << v << endl;
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (adj[u][i] == v)
            {
                adj[u].erase(adj[u].begin() + i);
            }
            else if(adj[v][i]==u)
            {
                adj[v].erase(adj[v].begin() + i);
            }
        }
    }
    else
    {
        cout << "Invalid range of edges" << endl;
    }
}
void Graph::search(int u,int v)
{
    if (u < n && v < n)
    {
        int flag=0;
        for (int i = 0; i < adj[u].size(); i++)
        {
            if (adj[u][i] == v)
            {
                cout<<"Edge is Found"<<endl;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"Edge not found"<<endl;
        }

    }
    else
    {
        cout << "Invalid range of edges" << endl;
    }
}
void Graph::TopoSort(int V)
{
    int vis[V]={0};
    stack<int> st;

    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            dfsTraversal(i,vis,st,adj);
        }
    }
    vector<int> vec;
    while(!st.empty()){
        vec.push_back(st.top());
        st.pop();
    }
    for(auto it :vec)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

int main()
{
    Graph g(5);
    while (true)
    {
        cout << "1.Insert\n2.Display\n3.Delete\n4.Search\n5.Exit" << endl;
        int choice, u, v;
        cout << "Enter choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the edge" << endl;
            cin >> u >> v;
            g.insert(u, v);
            break;

        case 2:
            g.display();
            break;
        case 3:
            cout << "Enter the edge" << endl;
            cin >> u >> v;
            g.Delete(u, v);
            break;
        case 4:
             cout<<"Enter the edge to be searched"<<endl;
             cin>>u>>v;
             g.search(u,v);
             break;
        case 5:
            cout << "TopoSort" << endl;
            g.TopoSort(5);
            break;
        }
    }
}