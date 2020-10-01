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

ll n, A, B;

void input(){
	cin >> n  >> A >> B;
}

void solve(){
	vll a(n);
	for(auto &it:a)cin >> it;
	sort(a.begin()+1, a.end());
	vll b(n);
	b[0] = a[0];
	for(ll i = 1; i < n; i++)b[i] = a[i] + b[i-1];
	for(ll i = n; i >= 1; i--){
		if(A*a[0]/b[i-1] >= B){
			cout << n - i;
			return;
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