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
	vll a(n);
	for(auto &it:a)cin >> it;
	vll b(101, 0);
	for(auto it:a)b[it]++;
	sort(rall(a));
	ll ans = 0;
	for(ll i = 1; i <= a[0] + a[min(sz(a)-1, 1ll)]; i++){
		ll t = 0;
		for(ll it = 1; it <= a[0]; it++) if(i - it >= 1)t+= min(b[it], b[i - it]);
		ans = max(ans, t/2);
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

