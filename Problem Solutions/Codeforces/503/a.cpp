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

ll n, h, a, b, k;

void input(){
	cin >> n >> h >> a >> b >> k;
}

void solve(){
	for(ll i = 0; i < k; i++){
		ll t1, f1, t2, f2;
		cin >> t1 >> f1 >> t2 >> f2;
		ll ans = abs(t1 - t2);
		if((f1 >= a and f1 <= b) or t1 == t2) cout << ans + abs(f1 - f2) << endl;
		else cout << min(ans + abs(f2 - a) + abs(f1 - a), ans + abs(f2 - b) + abs(f1 - b)) << endl;
	}
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
 