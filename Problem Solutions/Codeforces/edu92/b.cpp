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

ll n, k, z;

void input(){
	cin >> n >> k >> z;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	vll d(n), p(n, 0);
	d[0] = a[0];
	for(ll i = 1 ; i < n; i++)d[i] = a[i] + d[i-1];
	for(ll i = 1 ; i < n; i++)p[i] = max(a[i] + a[i-1], p[i-1]);
	ll ans = 0;
	for(ll i = 0; i <= z; i++){
		if(k < 2*i)break;
		ll j = k - 2*i;
		ans  = max(ans, d[j] + i*p[j+1]);
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