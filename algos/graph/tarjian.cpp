#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int citiesCnt = 0;
int curId = 0;
vector<int> nodeId;
vector<int> lowMinValue;
stack<int> active;
vector<int> in_active;

void dfs(int u)
{

	active.push(u);
	in_active[u] = 1;
	nodeId[u] = lowMinValue[u] = curId++;

	for (int &v : adj[u])
	{
		if (nodeId[v] == -1)
			dfs(v);

		if (in_active[v])
			lowMinValue[u] = min(lowMinValue[v], lowMinValue[u]);
	}

	if (nodeId[u] == lowMinValue[u])
	{

		while (active.size())
		{
			int node = active.top();
			active.pop();
			in_active[node] = 0;
			lowMinValue[node] = lowMinValue[u];
			if (node == u)
				break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

	int tc;
	cin >> tc;
	while (tc--)
	{

		int n, m;
		cin >> n >> m;

		while (active.size())
			active.pop();

		citiesCnt = 0;
		curId = 1;
		adj = vector<vector<int>>(n + 1);
		nodeId = vector<int>(n + 1, -1);
		lowMinValue = vector<int>(n + 1, -1);
		in_active = vector<int>(n + 1, 0);

		for (int i = 0; i < m; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}

		for (int i = 1; i <= n; i++)
		{
			if (nodeId[i] == -1)
				dfs(i);
		}

		map<int, int> cnts;
		for (int i = 1; i <= n; i++)
			cnts[lowMinValue[i]]++;

		vector<int> act_cnts;
		for (auto [__, cnt] : cnts)
			if (__ != -1)
				act_cnts.push_back(cnt);

		sort(act_cnts.rbegin(), act_cnts.rend());

		cout << (act_cnts.size() >= 1 ? act_cnts[0] : 0) + (act_cnts.size() >= 2 ? act_cnts[1] : 0) << "\n";
	}

	return 0;
}
