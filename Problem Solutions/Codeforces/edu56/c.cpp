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
	vll a(n/2);
	for(auto &it:a)cin >> it;
	vll ans(n);
	ans[0] = 0, ans[n-1] = a[0];
	ll l = 0, r = a[0];
	for(ll i = 1; i < n/2; i++){
		if(r < a[i] - l){
			ll d = a[i] - l - r;
			l += d;
		}
		ans[i] = l, ans[n - i - 1] = a[i] - l;
		r = a[i] - l;
	}
	
	for(auto it:ans)cout << it << " ";
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