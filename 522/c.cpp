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
	vll a(n);
	for(auto &it:a)cin >> it;
	ll dp[5][n];
	for(ll i = 0; i < 5; i++) for(ll j= 0; j < n; j++)dp[i][j] = -1;
	for(ll i = 0; i < 5; i++)dp[i][0] = 1;
	for(ll i = 1; i < n; i++){
		if(a[i] < a[i-1]){
			for(ll j = 0; j < 5; j++){
				for(ll k = j+1; k < 5; k++){
					if(dp[k][i-1] != -1){
						dp[j][i] = k;
						break;
					}
				}
			}
		}
		else if(a[i] > a[i-1]){
			for(ll j = 4; j >= 0; j--){
				for(ll k = j-1; k >= 0; k--){
					if(dp[k][i-1] != -1){
						dp[j][i] = k;
						break;
					}
				}
			}
		}
		else{
			for(ll j = 4; j >= 0; j--){
				for(ll k = 4; k >= 0; k--){
					if(dp[k][i-1] != -1 and k != j){
						dp[j][i] = k;
						break;
					}
				}
			}
		}
	}
	vll ans(n);
	ll t = -1, k = n-2;
	for(ll i = 0; i < 5; i++){
		if(dp[i][n-1] != -1){
			t = dp[i][n-1];
			ans[n-1] = i;
		}
	}
	if(t == -1) cout << -1;
	else{
		while(k >= 0){
			ans[k] = t;
			t = dp[t][k];
			k--;
		}
		for(auto it:ans)cout << it+1 << " ";
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