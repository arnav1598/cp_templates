#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector <ll> primes(ll up)
{
	vector <ll> vec;
	if(up>=2)
		vec.push_back(2);
	if(up>=3)
		vec.push_back(3);

	ll num=5, ind, p;
	int f;
	while(num<=up)
	{
		f=1;
		ind=0;
		p=vec[ind];
		while(p*p<=num)
		{
			if(num%p==0)
			{
				f=0;
				break;
			}
			ind++;
			p=vec[ind];
		}
		if(f==1)
			vec.push_back(num);
		
		num = num+2;
	}
	return vec;
}

ll EulerPhi(ll N)
{
	vector <int> pvec=primes(N);

	ll PF_idx = 0, PF = pvec[PF_idx], ans = N;
	while (PF * PF <= N)
	{
		if (N % PF == 0)
			ans -= ans / PF;
		while (N % PF == 0)
			N /= PF;
		PF = pvec[++PF_idx];
	}
	if (N != 1)
		ans -= ans / N;
	return ans;
}