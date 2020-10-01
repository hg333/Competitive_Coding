//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 998244353
#define pb emplace_back
#define vll vector<long long int>
#define ull unsigned long long
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll const nax = 3 * 10e5 + 5;
ll n, m;
bool f = true;
vll a[nax], col(nax, 0), vis(nax, 0), cnt(2, 0);

void dfs(ll v, ll c){
	if(vis[v])return;
	vis[v] = 1;
	col[v] = c;
	cnt[c]++;
	for(auto it:a[v]){
		if(!vis[it])dfs(it, 1 - c);
		else if(col[it] == col[v]) f = false;
	}
}

ll binpow(ll x, ll y) {
    x %= mod;
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void input(){
	cin >> n >> m;
	for(ll i = 1; i <= n; i++)a[i].clear();
	for(ll i = 1; i <= n; i++)col[i] = 0;
	for(ll i = 1; i <= n; i++)vis[i] = 0;
	f = true;
}

void solve(){
	for(ll i = 0; i < m; i++){
		ll u, v;
		cin >> u >> v;
		a[u].pb(v);
		a[v].pb(u);
	}
	ll res = 1;
	for(ll i = 1; i <= n; i++){
		cnt[1] = cnt[0] = 0;
		if(vis[i]) continue;
		dfs(i, 0);
		if(!f){
			cout << 0 << endl;
			return;
		}
		ll ans = (binpow(2, cnt[0]) + binpow(2, cnt[1]))%mod;
		res = (res * ans) % mod;
	}
	cout << res << endl;
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
        cout<<endl;
	}
	cin.get();
	return 0;
}