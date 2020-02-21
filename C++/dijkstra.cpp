#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

int dijks(int s, int t, vector<ii> adj[], const int& n)
{
	priority_queue<ii, vector<ii>, greater<ii> > q;
	int d[n];
	for (int i = 0; i < n; ++i) d[i] = long(1e9);

	d[s] = 0;
	q.push(ii(d[s], s));
	while (!q.empty())
	{
		ii tmp = q.top();
		int val = tmp.first, u = tmp.second;
		q.pop();
		if (val != d[u]) continue;
		
		if (u == t) return d[t];
		for (auto i : adj[u])
		{
			int v = i.first, x = i.second;
			if (d[v] > d[u] + x)
			{
				d[v] = d[u] + x;
				q.push(ii(d[v], v));
			}
		}
	}
	cerr << "done";
	return d[t];
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<ii> adj[n];
	while (m--)
	{
		int u, v, x;
		cin >> u >> v >> x;
		--u; --v;
		adj[u].push_back(make_pair(v, x));
		adj[v].push_back(make_pair(u, x));
	}
	int s, t;
	cin >> s >> t;
	--s; --t;
	cout << dijks(s, t, adj, n) << '\n';

	return 0;
}