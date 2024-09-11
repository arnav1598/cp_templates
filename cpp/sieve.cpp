#include <bits/stdc++.h>
using namespace std;
#define ll long long;

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

void segsieve(ll down, ll up, int* arr)
{
	if(down==0)
		sieve(up, arr);

	else
	{
	ll limit=sqrt(up)+1;
	int isprime[limit+1];
	sieve(limit, &isprime[0]);

	fill_n(arr, up-down+1, 1);

	if(down==1)
		arr[0]=0;
	ll lolim;
	for (ll i=2; i<=limit; i++)
	{
		if(isprime[i])
		{
			lolim = (down / i) * i;
        	if (lolim < down) 
            	lolim += i; 
        	if(lolim==i) 
        	    lolim += i; 
        	for (ll j = lolim; j <= up; j += i)
            	arr[j - down] = 0;
    	}
	}
	}
}

int main()
{
	ll up, down;
	cin >> up;
	int isprime[up+1];
	sieve(up, &isprime[0]);

	cin >> down;
	int segisprime[up-down+1];
	segsieve(down,up,&segisprime[0]);
}
