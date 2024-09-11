#include <bits/stdc++.h>
using namespace std;
#define ll long long

void sieve(ll up, int* arr)
{
	fill_n(arr, up+1, 1);
	*arr=0;
	*(arr+1)=0;

	for (ll i=2; i*i<=up; i++)
		if(*(arr+i)==1)
			for (ll j=i*i; j<=up; j+=i)
				*(arr+j)=0;
}

vector<ll> factors(ll n)
{
	ll m=sqrt(n)+1;
	int isprime[m+1];
	sieve(m, &isprime[0]);
	
	vector<ll> v;

	for (ll i=2; i*i<=n; i++)
	{
		if(isprime[i]==1)
			while (n%i==0)
			{
				v.push_back(i);
				n=n/i;
			}
		if (n==1)
			return v;
	}
	if (n!=1)
		v.push_back(n);

	return v;

}

int main()
{
	ll n;
	cin >> n;
	vector<ll> fac=factors(n);
}
