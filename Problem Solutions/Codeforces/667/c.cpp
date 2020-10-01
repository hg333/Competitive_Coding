//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n, a, b;

void input(){
	cin >> n >> a >> b;
}

void solve(){
	ll x = b-a;
	n -= 1;
	ll d = 1;
	for(ll i = n; i >= 1; i--){
		if(x%i==0){
			d = x/i;
			break;
		}
	}
	n--;
	vll ans;
	ans.pb(a), ans.pb(b);
	for(ll i = a+d; i <= b-d; i += d){
		if(!n)break;
		ans.pb(i);
		n--;
	}
	for(ll i = a - d; i >= 1; i-=d){
		if(!n)break;
		ans.pb(i);
		n--;
	}
	for(ll i = b + d; i <= 10e9; i+=d){
		if(!n)break;
		ans.pb(i);
		n--;
	}
	sort(all(ans));
	for(auto it:ans)cout << it << " ";
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	cin >> t;
	while(t--){
		input();
		solve();
	}
	cout << endl;
	cin.get();
	return 0;
}