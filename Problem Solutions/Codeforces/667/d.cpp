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

ll n, s;

void input(){
	cin >> n >> s;
}

ll binpow(ll a,ll b){
	if(!b)return 1;
	ll res = binpow(a, b/2);
	if(b%2)return res*res*a;
	else return res*res;
}

void solve(){
	vll a(20, 0);
	for(ll i = 0; i < 20; i++){
		a[i] = n%10;
		n/=10;
	}
	ll su = 0;
	for(auto it:a)su += it;
	if(su <= s) cout << 0 << endl;
	else{
		ll ans = 0;
		for(ll i = 0; i < 20; i++){
			if(!a[i])continue;
			ans += binpow(10,(i+1));
			for(ll j = i+1; j < 20; j++){
				a[j]++;
				if(a[j] == 10)a[j] = 0;
				else break;
			}
			su = 0;
			for(auto it:a)su += it;
			while(a[i] > 0 and su > s){
				a[i]--;
				ans -= binpow(10,i);
				su--;
			}
			while(a[i] > 0){
				a[i]--;
				ans -= binpow(10,i);
			}
			if(su <= s) break;
		}
		cout << ans << endl;
	}
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
	cout << endl;
	cin.get();
	return 0;
}
	