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

void input(){
}

void solve(){
	string s;
	cin >> s;
	ll n = sz(s);
	ll a[10] = {0};
	for(ll i = 0; i < n; i++)a[s[i] - '0']++;
	ll ans = n-2;
	for(ll i = 0; i < 10; i++) ans = min(ans, n - a[i]);
	for(ll i = 0; i < 10; i++) for(ll j = 0; j < 10; j++) if(i != j){
		ll u = i, v = j, t = 0;
		for(ll k = 0; k < n; k++){
			if(s[k] - '0' == u){
				swap(u, v);
				t++;
			}
		}		
		if(t%2) t--;
		ans = min(ans,n - t);
	}
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
        cout<<endl;
	}
	cin.get();
	return 0;
}