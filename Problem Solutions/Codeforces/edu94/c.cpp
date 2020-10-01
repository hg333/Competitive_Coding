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

string s;
ll x;

void input(){
	cin >> s >> x;
}

void solve(){
	string ans;
	ll n = sz(s);
	ans.resize(sz(s));
	for(ll i = 0; i < n; i++)ans[i] = '1';
	for(ll i = 0; i < n; i++){
		if(s[i] == '1')continue;
		if(i+x < n)ans[i+x] = '0';
		if(i-x >= 0)ans[i-x] = '0';
	}
	bool f = true;
	for(ll i = 0; i < n; i++){
		bool g = true;
		if(s[i] == '0'){
			if(i+x < n)g &= (ans[i+x] == s[i]);
			if(i-x >= 0)g &= (ans[i-x] == s[i]);
		}
		else{
			g = false;
			if(i+x < n)g |= (ans[i+x] == s[i]);
			if(i-x >= 0)g |= (ans[i-x] == s[i]);
		}
		f &= g;
	}
	if(f)cout << ans << endl;
	else cout << -1 << endl;
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
	cin.get();
	return 0;
}

