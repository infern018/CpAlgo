#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define el "\n"
#define mnl *min_element
#define mxl *max_element


typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;

//---------------------------------------------------------------
// TO REMOVE DUPLICATES FROM VECTOR
// sort( vec.begin(), vec.end() );	
// vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
//---------------------------------------------------------------

//It stores prime numbers in is_prime

const int MAX = 10010896;

int main() 
{
	//mazik:
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n=10000000;

	vector<char> is_prime(n+1, true);

	is_prime[0]=false;
	is_prime[1]=false;

	for(int i=2;i*i<=n;i++)
	{
		if(is_prime[i])
		{
			for(int j=i*i;j<=n;j+=i)
				is_prime[j]=false;
		}
	}

	REP(i,0,is_prime.size())
	{
		if(is_prime[i] && i%4==3)
		{
			is_prime[i]=false;
		}
	}

	vi v(n+1,0);

	for(int x=0;x*x<n;x++)
	{
		for(int y=0;y*y*y*y<n;y++)
		{
			int p=x*x;
			int q=y*y*y*y;

			int n1=p+q;

			if(n1<n && is_prime[n1])
				v[n1]=1;
		}
	}

	REP(i,1,v.size())
	{
		v[i]+=v[i-1];
	}

	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;

		cout<<v[n]<<el;
	}
}