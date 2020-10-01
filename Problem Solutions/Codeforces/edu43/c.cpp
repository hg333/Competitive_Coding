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

bool mc(pair<pll, ll> p1, pair<pll, ll> p2){
	if(p1.f.s == p2.f.s) return p1.f.f < p2.f.f;
	return p1.f.s > p2.f.s;
}

void solve(){
	vector<pair<pll, ll>> a(n);
	for(ll i = 0; i < n; i++)cin >> a[i].f.f >> a[i].f.s, a[i].s = i+1;
	sort(all(a), mc);
	vll t(n);
	t[n-1] = a[n-1].f.f;
	for(ll i = n-2; i >= 0; i--) t[i] = max(t[i+1], a[i].f.f);
	for(ll i = 0; i < n-1; i++){
		if(t[i+1] >= a[i].f.f){
			for(ll j = i+1; j < n; j++){
				if(a[j].f.f == t[i+1]){
					cout << a[j].s << " " << a[i].s;
					return;
				}
			}
		}
	}
	cout << "-1 -1";
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