#include <bits/stdc++.h>
using namespace std;

vector<int> path;

vector<bool> indeg0, outdeg0;

vector<vector<int> > adj;

vector<bool> visited;

// Recursive function to print all paths
void dfs(int s)
{
	
	path.push_back(s);
	visited[s] = true;

	
	if (outdeg0[s] && indeg0[path[0]]) {
		for (auto x : path)
			cout << x << " ";
		cout << '\n';
	}

	for (auto node : adj[s]) {
		if (!visited[node])
			dfs(node);
	}

	path.pop_back();
	visited[s] = false;
}

void print_all_paths(int n)
{
	for (int i = 0; i < n; i++) {
		// for each node with in-degree 0
		// print all possible paths
		if (indeg0[i] && !adj[i].empty()) {
			dfs(i);
		}
	}
}

// Driver Code
int main()
{
	int n;
	n = 6;

	visited = vector<bool>(n, false);

	adj = vector<vector<int> >(n);

	indeg0 = vector<bool>(n, true);
	outdeg0 = vector<bool>(n, true);

	vector<pair<int, int> > edges
		= { { 5, 0 }, { 5, 2 }, { 2, 3 },
			{ 4, 0 }, { 4, 1 }, { 3, 1 } };

	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].first;
		int v = edges[i].second;

		adj[u].push_back(v);

		indeg0[v] = false;

		outdeg0[u] = false;
	}
	cout << "All possible paths:\n";
	print_all_paths(n);
	return 0;
}
