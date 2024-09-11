#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
	private:
		vector<int> p, rank, setsize;
		int numsets;
	public:
		UnionFind(int N)
		{
			rank.assign(N, 0);
			setsize.assign(N, 1);
			numsets = N;
			p.assign(N, 0);
			for (int i = 0; i < N; i++)
				p[i] = i;
		}

		int findSet(int i)
		{
			return (p[i] == i) ? i : (p[i] = findSet(p[i]));
		}
		bool isSameSet(int i, int j)
		{
			return findSet(i) == findSet(j);
		}
		void unionSet(int i, int j)
		{
			if (!isSameSet(i, j)) 
			{
				numsets--;
				int x = findSet(i), y = findSet(j);
				if (rank[x] > rank[y])
				{
					p[y] = x;
					setsize[x] += setsize[y];
				}
				else
				{
					p[x] = y;
					setsize[y] += setsize[x];
					if (rank[x] == rank[y])
						rank[y]++;
				}
			}
		}
		int numDisjointSets()
		{
			return numsets;
		}
		int sizeOfSet(int i)
		{
			return setsize[findSet(i)];
		}
};

