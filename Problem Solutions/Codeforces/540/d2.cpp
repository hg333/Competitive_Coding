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

ll n, m;
vll a;

void input(){
	cin >> n >> m;
	a.resize(n);
}

bool chk(ll i){
	ll su = 0;
	for(ll j = 0; j < n; j++) su += max(0ll, a[j] - j/i);
	if(su >= m) return true;
	return false;
}

void solve(){
	for(auto &it:a)cin >> it;
	sort(rall(a));
	ll l = 1, r = n, midd = inf;
	while(l <= r){
		ll mid = l + (r - l)/2;
		if(chk(mid))midd = mid, r = mid - 1;
		else l = mid + 1;
	}
	if(midd == inf) cout << -1;
	else cout << midd;
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