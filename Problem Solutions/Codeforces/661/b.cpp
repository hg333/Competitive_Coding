//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
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

ll n;

void input(){
	cin >> n;
}

void solve(){
	vll a(n), b(n);
	for(auto &it:a)cin >> it;
	for(auto &it:b)cin >> it;
	ll x = inf, y = inf;
	for(auto it:a)x = min(it,x);
	for(auto it:b)y = min(it,y);
	ll ans = 0;
	for(ll i = 0; i < n; i++) ans += min(abs(a[i]-x), abs(b[i]-y)) + abs(abs(a[i]-x) - abs(b[i]-y));
	cout << ans << endl;
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
	cout<<endl;
	cin.get();
	return 0;
}

