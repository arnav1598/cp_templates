#define inf INT_MAX

void bfs()
{

	//vector <vector<int>> graph;
	//int s;

	vector <int> dist(graph.size(), inf);
	dist[s]=0;

	queue<int> q;
	q.push(s);

	while(!q.empty())
	{
		int u = q.front();
		q.pop();

		for (int i=0; i<graph[u].size(); i++)
		{
			int v = graph[u][i];

			if (dist[v] == inf)
			{
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
}

void dfs()
{

	//vector <vector<int>> graph;

	vector <int> parent(graph.size(), -1)
	vector <int> flag(graph.size(), 0);
	vector <pair<int,int>> edge, back, fwd;
	int n_comp = 0;

	for (int i=0; i<graph.size(); i++)
		if (flag[i]==0)
		{
			n_comp += 1;
			stack <int> st;
			st.push(s);

			while(!st.empty())
			{
				int u = st.top();

				if(flag[u]==1)
				{
					st.pop();
					flag[u]=2;
					continue;
				}

				flag[u]=1;

				for (int j=0; j<graph[u].size(); j++)
				{
					int v = graph[u][i];

					if (flag[v]==0)
					{
						parent[v] = u;
						st.push(v);
					}
					else if (flag[v]==1)
					{
						if (parent[u]==v)
						{
							edge.push_back(make_pair(u,v));
							edge.push_back(make_pair(v,u));
						}
						else
						{
							back.push_back(make_pair(u,v))
						}
					}
					else
					{
						fwd.push_back(make_pair(u,v));
					}
				}
			}
		}
}

void kruskal()
{

	//vector <pair<int, pair<int,int>>> edgelist;

	sort(edgelist.begin(), edgelist.end());

	int mst_cost=0;
	vector <pair<int,int>> taken_edge;

	UnionFind uf(edgelist.size());

	for (int i=0; i<edgelist.size(); i++)
	{
		if (!uf.isSameSet(edgelist[i].second.first, edgelist[i].second.second))
		{
			mst_cost += edgelist[i].first;
			uf.unionSet(edgelist[i].second.first, edgelist[i].second.second);
			taken_edge.push_back(make_pair(edgelist[i].second.first, edgelist[i].second.second));
		}
	}
}

void prim()
{

	//vector <vector <pair<int,int>>> graph;

	vector <int> taken(graph.size(), 0);
	priority_queue <pair<int,int>> pq;

	taken[0]=1;

	for (int j=0; j<graph[0].size(); j++)
		if(!taken[graph[0][j].first])
			pq.push(make_pair(-1*graph[0][j].second, -1*graph[0][j].first));

	int mst_cost=0;

	while(!pq.empty())
	{
		pair<int,int> f = pq.top();
		pq.pop();
		int u = -1*f.second;
		int w = -1*f.first;

		if(!taken(u))
		{
			mst_cost += w;

			taken[u]=1;

			for (int j=0; j<graph[u].size(); j++)
				if(!taken[graph[u][j].first])
					pq.push(make_pair(-1*graph[u][j].second, -1*graph[u][j].first));
		}
	}
}

void dijkstra()
{

	//vector <vector <pair<int,int>>> graph;
	//int s;

	vector <int> dist(graph.size(), inf);
	vector <int> parent(graph.size(), -1);
	dist[s]=0;
	parent[s]=s;

	priority_queue< pair<int,int> ,vector <pair<int,int>>, greater<pair<int,int>> > pq;
	pq.push(make_pair(0, s));

	while(!pq.empty())
	{
		pair<int,int> f = pq.top;
		pq.pop();

		int d = f.first;
		int u = f.second;

		if(d>dist[u])
			continue;

		for (int j=0; j<graph[u].size(); j++)
		{
			pair<int,int> v = graph[u][j];

			if (dist[u] + v.second < dist[v.first])
			{
				dist[v.first] = dist[u] + v.second;
				parent[v] = u;
				pq.push(make_pair(dist[v.first], v.first));
			}
		}
	}

}

void bellman_ford()
{

	//vector <vector <pair<int,int>>> graph;
	//int s;

	vector <int> dist(graph.size(), inf);
	vector <int> parent(graph.size(), -1);
	dist[s]=0;
	parent[s]=s;

	for (int i=0; i<graph.size()-1; i++)
		for (int u=0; u<graph.size(); u++)
			for (int v=0; v<graph[u].size; v++)
				if (dist[u] + graph[u][v].second < dist[graph[u][v].first])
				{
					dist[graph[u][v].first] = dist[u] + graph[u][v].second;
					parent[graph[u][v].first] = u;
				}
}

void floyd_warshal()
{
	//int adjmat[n][n];
	//int n;

	int p[n][n];

	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			p[i][j]=i;

	for (int k=0; k<n; k++)
		for (int i=0; i<n; i++)
			for (int j=0; j<n; j++)
			{
				if (adjmat[i][k] + adjmat[k][j] < adjmat[i][j])
					{
						adjmat[i][j] = adjmat[i][k] + adjmat[k][j];
						p[i][j] = p[k][j];
					}
			}
}

