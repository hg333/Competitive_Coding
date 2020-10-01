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

ll a, b, x, y, n;

void input(){
	cin >> a >> b >> x >> y >> n;
}

void solve(){
	if(a - min(n, a - x) > b - min(n, b - y)){
		ll p = min(n, b - y);
		n -= p;
		b -= p;
		p = min(n, a - x);
		n -= p;
		a -= p;
	}
	else{
		ll p = min(n, a - x);
		n -= p;
		a -= p;
		p = min(n, b - y);
		n -= p;
		b -= p;
	}
	cout << a*b << endl;
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