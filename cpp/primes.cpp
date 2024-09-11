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