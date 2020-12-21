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

int main() 
{
	//mazik:
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n1=5300000;

	vector<char> is_prime(n1+1, true);

	is_prime[0]=false;
	is_prime[1]=false;

	for(int i=2;i*i<=n1;i++)
	{
		if(is_prime[i])
		{
			for(ll j=i*i;j<=n1;j+=i)
				is_prime[j]=false;
		}
	}

	vector<ll> prs;

	REP(i,0,is_prime.size())
	{
		if(is_prime[i])
		{
			prs.PB(i);
		}
	}

	vector<ll> lst;

	REP(i,0,365560)
	{
		REP(j,i+1,365560)
		{
			if(prs[i]*prs[j] > 10527451)
				break;

			lst.PB(prs[i]*prs[j]);
		}
	}

	sort(lst.begin(), lst.end());

	int t;
	cin>>t;

	while(t--)
	{
		int k;
		cin>>k;

		cout<<lst[k-1]<<el;
	}

	// REP(i,0,lst.size())
	// {
	// 	cout<<lst[i]<<el;
	// }

}