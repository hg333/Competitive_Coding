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
	vector<pll> a(n);
	for(auto &it:a)cin >> it.f >> it.s;
	vll b(n);
	for(ll i = 0; i < n; i++){
		ll m = a[i].f * 60 + a[i].s;
		if(!i)b[0] = m;
		else b[i] = m - (a[i-1].f * 60 + a[i-1].s) - 1;
	}
	for(ll i = 0; i < n; i++){
		if(b[i] >= 2*k + 1 or (!i and b[i] >= k + 1)){
			ll t;
			if(!i) t = 0;
			else {
				t = a[i-1].f * 60 + a[i-1].s;
				t += k + 1;
			}
			cout << t/60 << " " << t%60;
			return;
		}
	}
	ll i = n;
	ll t = a[i-1].f * 60 + a[i-1].s;
	t += k + 1;
	cout << t/60 << " " << t%60;
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