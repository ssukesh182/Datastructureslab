#include <iostream>
#include <vector>
#include <stack>
#include<set>
using namespace std;

class Graph
{
private:
    int n;
    vector<pair<int, int>> *adj; 

public:
    Graph(int V)
    {
        n = V;
        adj = new vector<pair<int, int>>[n];
    }

    void insert(int u, int v, int weight);
    void display();
    void Delete(int u, int v);
    void search(int u, int v);
    void dfs(int V);
    void dfsTraversal(int, int[], stack<int>&, vector<pair<int, int>>*);
	void DijkstraAlgorithm(int V,int S);
};

void Graph::DijkstraAlgorithm(int V,int S)
{
	vector<int> dis(V,1e9);
	set<pair<int,int>> st;
	dis[S]=0;
	st.insert({0,S});

	while(!st.empty())
	{
		auto it=*(st.begin());
		int dist=it.first;
		int Node=it.second;
		st.erase(it);
		for(auto i:adj[Node]){
			int adjnode=i.first;
			int edgeweight=i.second;

			if(dist+edgeweight<dis[adjnode]){
				if(dis[adjnode] != 1e9) {st.erase({dis[adjnode], adjnode});}
				dis[adjnode]=dist+edgeweight;
				st.insert({dis[adjnode],adjnode});
			}
		}
	}
	for(auto it:dis){
		cout<<it<<endl;
	}

}
void Graph::insert(int u, int v, int weight)
{
    if (u < n && v < n)
    {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // because undirected
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
        cout << i << " -> [ ";
        for (auto it : adj[i])
        {
            cout << "(" << it.first << ", " << it.second << ") ";
        }
        cout << "]" << endl;
    }
}

void Graph::Delete(int u, int v)
{
    if (u < n && v < n)
    {
        cout << "Deleted edge between: " << u << " and " << v << endl;
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it)
        {
            if (it->first == v)
            {
                adj[u].erase(it);
                break;
            }
        }
        for (auto it = adj[v].begin(); it != adj[v].end(); ++it)
        {
            if (it->first == u)
            {
                adj[v].erase(it);
                break;
            }
        }
    }
    else
    {
        cout << "Invalid range of edges" << endl;
    }
}

void Graph::search(int u, int v)
{
    if (u < n && v < n)
    {
        int flag = 0;
        for (auto it : adj[u])
        {
            if (it.first == v)
            {
                cout << "Edge Found with weight: " << it.second << endl;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            cout << "Edge not found" << endl;
        }
    }
    else
    {
        cout << "Invalid range of edges" << endl;
    }
}

void Graph::dfsTraversal(int node, int vis[], stack<int>& st,vector<pair<int, int>>* adj)
{
    vis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i.first])
        {
            dfsTraversal(i.first, vis, st, adj);
        }
    }
    st.push(node);
}

void Graph::dfs(int V)
{
    int vis[V] = {0};
	stack<int> st;
    int start=0;
	dfsTraversal(start,vis,st,adj);
	while(!st.empty())
	{
		cout<<st.top()<<endl;
		st.pop();
	}
}

int main()
{
    Graph g(6);
    while (true)
    {
        cout << "1. Insert\n2. Display\n3. Delete\n4. Search\n5. TopoSort\n6. Exit" << endl;
        int choice, u, v, weight;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the edge (u v weight): ";
            cin >> u >> v >> weight;
            g.insert(u, v, weight);
            break;
        case 2:
            g.display();
            break;
        case 3:
            cout << "Enter the edge to delete (u v): ";
            cin >> u >> v;
            g.Delete(u, v);
            break;
        case 4:
            cout << "Enter the edge to search (u v): ";
            cin >> u >> v;
            g.search(u, v);
            break;
        case 5:
            cout << "DFS" << endl;
            g.dfs(5);
            break;
        case 6:
		    g.DijkstraAlgorithm(6,0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
