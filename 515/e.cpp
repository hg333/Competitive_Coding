//g++ -Wshadow -Wall -O2 -Wno-unused-result -Wno-psabi
#include "bits/stdc++.h"
#define f first
#define s second
#define inf 1e18
#define ll long long
#define mod 998244353
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

ll binpow(ll a, ll b) {
    a %= mod;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve(){
	string a, b;
	cin >> a >> b;
	string d = string(abs(sz(a) - sz(b)), '0');
	cout << d;
	if(sz(a) > sz(b)){
		string c = d;
		c += b;
		b = c;
	}
	else if(sz(b) > sz(a)){
		string c = d;
		c += a;
		a = c;
	}
	ll n = max(n, m), ans = 0;
	for(ll i = 0; i < n; i++) if(a[i] == b[i] and a[i] == '1') ans = (ans + binpow(2, n - i - 1))%mod;
	ll t = ans, l = 0;
	for(ll i = n-1; i >= 0; i--){
		if(a[i - l] == b[i] and b[i] == '1')
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