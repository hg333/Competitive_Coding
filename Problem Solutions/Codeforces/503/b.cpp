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

ll n;
ll const nax = 2000;
vll a(nax), vis(nax, 0);
ll t = -1;

void dfs(ll v){
	vis[v] = 1;
	if(!vis[a[v]])dfs(a[v]);
	else if(t == -1)t = a[v];
}

void input(){
	cin >> n;
}

void solve(){
	for(ll i = 1; i <= n; i++){
		ll v;
		cin >> v;
		a[i] = v;
	}
	
	for(ll i = 1; i <= n; i++){
		vis.assign(nax, 0);
		t = -1;
		dfs(i);
		cout << t << " ";
	}
	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll T = 1;
	//cin >> t;
	while(T--){
		input();
		solve();
		cout<<endl;
	}
	cin.get();
	return 0;
}

	