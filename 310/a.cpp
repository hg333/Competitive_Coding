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
	ll gt = 0, ans = 0;
	for(ll i = 0; i < k; i++){
		ll d, t = 0;
		bool f = false;
		cin >> d;
		vll a(d);
		for(auto &it:a)cin >> it;
		for(ll j = 0; j < d; j++) {
			if(j+1 != a[j])t++, gt++;
			else f = true;
		}
		if(f) gt++, t++;
		ans += t-1;
	}
	ans += gt-1;
	cout << ans;
	
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