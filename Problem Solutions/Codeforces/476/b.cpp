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

ll n, K;

void input(){
	cin >> n >> K;
}

void solve(){
	char a[n][n];
	for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++)cin >> a[i][j];
	ll ans = 0, x = 1, y = 1;
	for(ll i = 0; i < n; i++) for(ll j = 0; j < n; j++){
		if(a[i][j] == '#') continue;
		ll k = i, t1 = 0, t2 = 0;
		while(k < min(n, i+K) and a[k][j] != '#')t1++,k++;
		k = i;
		while(k >= max(0ll, i-K+1) and a[k][j] != '#')t1++,k--;
		k = j;
		while(k < min(n, j+K) and a[i][k] != '#')t2++,k++;
		k = j;
		while(k >= max(0ll, j-K+1) and a[i][k] != '#')t2++,k--;	
		t1--, t2--;
		if(ans < max(0ll, t1 - K + 1) + max(0ll, t2 - K + 1)){
			ans = max(0ll, t1 - K + 1) + max(0ll, t2 - K + 1);
			x = i+1, y = j+1;
		}
	}
	
	cout << x << " " << y;
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