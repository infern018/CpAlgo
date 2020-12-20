//TDPRIMES-SPOJ

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

int main() 
{
	//mazik:
    ios::sync_with_stdio(0);
	cin.tie(0);

	int n=100000000;

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

	int cnt=1;
	cout<<2<<el;

	REP(i,3,is_prime.size())
	{
		if(is_prime[i])
		{
			cnt++;
		}

		if(cnt%100==1 && is_prime[i])
		{
			cout<<i<<el;
		}
	}

}