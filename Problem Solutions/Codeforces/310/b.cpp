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

void input(){
	cin >> n >> m;
}

void solve(){
	vector<pll> a(n), b(m);
	for(auto &it:a)cin >> it.f >> it.s;
	vll ans;
	for(ll i = 0; i < m; i++){
		pll it;
		cin >> it.f; it.s = i+1;
		b[i] = it;
	}
	multiset<ll> s;
	for(auto it:b)s.insert(it.f);
	sort(all(b));
	for(ll i = 0; i < n-1; i++){
		ll d = a[i+1].f - a[i].s, D = a[i+1].s - a[i].f;
		auto it = s.lower_bound(d);
		if(it != s.end() and *it <= D){
			ll x = *it;
			s.erase(it);
			ans.pb(x);
		}
		else {
			cout << d;
			cout << "No";
			return;
		}
	}
	
	cout << "Yes\n";
	for(auto it:ans){
		ll l = 0, r = m-1, midd = -1;
		while(l <= r){
			ll mid = l + (r-l)/2;
			if(it > b[mid].f)l = mid + 1;
			else if (it < b[mid].f)r = mid - 1;
			else{
				midd = mid;
				break;
			}
		}
		b[midd].f = -1;
		cout << b[midd].s << " ";
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