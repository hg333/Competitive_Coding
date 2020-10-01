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
#define all(a) a.begin(),a.end ()
#define rall(a) a.rbegin(),a.rend()
#define sz(x) ((long long int)(x).size())
#define mll map<long long int, long long int>
#define pll pair<long long int, long long int>
using namespace std;

ll n, m, c1, c2, v, q;
vll str, ele;

void input(){
	cin >> n >> m >> c1 >> c2 >> v;
	str.resize(c1), ele.resize(c2);
	if(sz(str))for(auto &it:str) cin >> it;
	if(sz(ele))for(auto &it:ele) cin >> it;
	cin >> q;
}

bool chkbtw(ll x1,ll x2){
	ll l = 0, r = sz(str) - 1;
	while(l <= r){
		ll mid = l + (r-l)/2;
		if(str[mid] >= x1 and str[mid] <= x2) return true;
		else if(str[mid] >= x1) r = mid - 1;
		else l = mid + 1;
	}
	return false;
}

bool chkbtw2(ll x1,ll x2){
	ll l = 0, r = sz(ele) - 1;
	while(l <= r){
		ll mid = l + (r-l)/2;
		if(ele[mid] >= x1 and ele[mid] <= x2) return true;
		else if(ele[mid] >= x1) r = mid - 1;
		else l = mid + 1;
	}
	return false;
}

void solve(){
	while(q--){
		ll i1, j1, i2, j2;
		cin >> j1 >> i1 >> j2 >> i2;
		ll ans = inf, t1 = inf, t2 = inf, t3 = inf, t4 = inf, t5 = inf, t6 = inf, t7 = inf;
		ll x1 = min(i1, i2), x2 = max(i1, i2);
		if(sz(str)){			
			if(chkbtw(x1, x2)) t3 = abs(i1 - i2) + abs(j1 - j2);
			else{
				auto it = upper_bound(all(str), x1), jt = lower_bound(all(str), x2);
				if(it != str.begin()){
					it--;
					t1 = abs(i1 - i2) + abs(j1 - j2) + 2*abs(x1 - *it);
				}
				if(jt != str.end()) t2 = abs(i1 - i2) + abs(j1 - j2) + 2*abs(x2 - *jt);
			}
		}
		if(sz(ele)){
			if(chkbtw2(x1, x2)) t4 = abs(i1 - i2) + (abs(j1 - j2) + v-1)/v;
			else{
				auto it = upper_bound(all(ele), x1), jt = lower_bound(all(ele), x2);
				if(it != str.begin()){
					it--;
					t5 = abs(i1 - i2) + (abs(j1 - j2) + v-1)/v + 2*abs(x1 - *it);
				}
				if(jt != str.end()) t6 = abs(i1 - i2) + (abs(j1 - j2) + v-1)/v + 2*abs(x2 - *jt);
			}
		}
		if(j1 == j2)t7 = abs(i1 - i2) + abs(j1 - j2);
		ans = min({t1, t2, t3, t4, t5, t6, t7});
		cout << ans << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);
	ll t = 1;
	// cin >> t;
	while(t--){
		input();
		solve();
        cout<<endl;
	}
	cin.get();
	return 0;
}