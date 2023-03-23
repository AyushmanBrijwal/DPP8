#include<bits/stdc++.h>
using namespace std;
void Nodes(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

void func(int u, vector<int> adj[],
			vector<bool> &visited)
{
	list<int> q;

	visited[u] = true;
	q.push_back(u);

	while(!q.empty())
	{
		u = q.front();
		cout << u << " ";
		q.pop_front();
		for (int i = 0; i != adj[u].size(); ++i)
		{
			if (!visited[adj[u][i]])
			{
				visited[adj[u][i]] = true;
				q.push_back(adj[u][i]);
			}
		}
	}
}

void BFS(vector<int> adj[], int V)
{
	vector<bool> visited(V, false);
	for (int u=0; u<V; u++)
		if (visited[u] == false)
			func(u, adj, visited);
}

int main()
{
	int V = 5;
	vector<int> adj[V];

	Nodes(adj, 0, 4);
	Nodes(adj, 0, 2);
	Nodes(adj, 1, 3);
	Nodes(adj, 1, 4);
	Nodes(adj, 2, 3);
	Nodes(adj, 2, 4);
	BFS(adj, V);
	return 0;
}
