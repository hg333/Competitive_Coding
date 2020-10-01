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

ll n, k;

void input(){
	cin >> n >> k;
}

void solve(){
	vll a(n);
	string s;
	for(auto &it:a)cin >> it;
	cin >> s;
	ll ans = 0;
	for(ll i = 0; i < n;){
		ll j = i + 1;
		vll b;
		b.pb(a[i]);
		while(j < n and s[i] == s[j]){
			b.pb(a[j]);
			j++;
		}
		i = j;
		sort(rall(b));
		for(ll x = 0; x < min(k, sz(b)); x++)ans += b[x];
		cout << endl;
	}
	cout << ans;
	
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