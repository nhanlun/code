#include <bits/stdc++.h>

using namespace std;

bool DFS(int x, int& drain, vector<int>* adj, bool* visited)
{
	// cerr << x << '\n';
	visited[x] = true;
	if (x == drain) return true;
	for (auto i:adj[x])
	{
		if (!visited[i])
		{
			if (DFS(i, drain, adj, visited)) return true;
		}
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	vector<int> adj[n];
	int x, y, z;
	while (cin >> x >> y >> z && x != 0 && y != 0 && z != 0)
	{
		--x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	cin >> x >> y;
	--x; --y;
	bool* visited = new bool[n];
	for (int i = 0; i < n; ++i) visited[i] = false;
	if (DFS(x, y, adj, visited)) cout << "YES"; 
	else cout << "NO";

	delete[] visited;
	return 0;
}