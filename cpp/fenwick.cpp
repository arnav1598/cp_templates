#include <bits/stdc++.h>
using namespace std;

class FenwickTree
{
	private:
		vector <int> ft;

		int LSOne(int S)
		{
			return (S & (-S));
		}

	public:
		FenwickTree(int n)
		{
			ft.assign(n + 1, 0);
		}

		int rsq(int b) // returns RSQ(1, b)
		{
			int sum = 0;
			
			for (; b; b -= LSOne(b))
				sum += ft[b];

			return sum;
		}
		
		int rsq(int a, int b) // returns RSQ(a, b)
		{
			return rsq(b) - (a == 1 ? 0 : rsq(a - 1));
		}
		
		void adjust(int k, int v) // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
		{
			// note: n = ft.size() - 1
			for (; k <= (int)ft.size() - 1; k += LSOne(k))
				ft[k] += v;
		}
};