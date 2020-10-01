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

ll n, mxfr = -inf;
const ll nax = 10e5+5;
ll fr[nax] = {0};
mll frfr;

void input(){
	cin >> n;
}

void solve(){
	vll a(n);
	ll ans = 0;
	for(auto &it:a)cin >> it;
	for(ll i = 1; i <= n; i++){
		fr[a[i-1]]++;
		mxfr = max(mxfr, fr[a[i-1]]);
		frfr[fr[a[i-1]]-1]-- ;
		frfr[fr[a[i-1]]]++;
		bool f = false;
		if(frfr[1] == i)f = true;
		else if(frfr[i] == 1)f = true;
		else if(frfr[1] == 1 and frfr[mxfr] * mxfr == i - 1)f = true;
		else if(frfr[mxfr] == 1 and frfr[mxfr-1] * (mxfr - 1) == i - mxfr)f = true;
		if(f)ans = i;
	}
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