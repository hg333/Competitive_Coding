//g++ -std=c++17 -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 1000000007
#define pb push_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n, r;

void input(){
	cin >> n >> r;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	vector<pll> b;
	for(ll i = 0; i < n; i++){
		if(a[i]) b.pb({max(0ll, i - r + 1), min(n-1, i + r - 1)});
	}
	vll c(n, 0);
	sort(all(b));
	for(ll i = 0; i < sz(b); i++) for(ll j = b[i].f; j <= b[i].s; j++) c[j]++;
	for(auto it:c){
		if(!it){
			cout << -1;
			return;
		}
	}
	ll ans = sz(b);
	for(ll i = 0; i < sz(b); i++){
		bool g = true;
		for(ll j = b[i].f; j <= b[i].s; j++){
			if(c[j] <= 1) g = false;
		}
		
		if(g){
			for(ll j = b[i].f; j <= b[i].s; j++)c[j]--;
			ans--;
		}
	}
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	//cin >> t;
	while(t--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}

