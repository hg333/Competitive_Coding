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
mll mp;

void input(){
	cin >> n;
}

void solve(){
	ll l = inf, r = inf;
	for(ll i = 0; i < n; i++){
		string s;
		ll d;
		cin >> s >> d;
		if(s == "L"){
			if(l == inf)l = r = 0;
			else l--;
			mp[d] = l;
		}
		else if(s == "R"){
			if(r == inf)l = r = 0;
			else r++;
			mp[d] = r;
		}
		else{
			cout << min(abs(mp[d] - r), abs(mp[d] - l)) << endl;
		}
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