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
	if(n == 1) cout << "1 1\n0\n1 1\n" << 0 << endl << "1 1\n" << -a[0];
	else{
		cout << "1 1\n" << -a[0] << endl;
		a[0] = 0;
		cout << "1 " << n << endl;
		for(ll i = 0; i < n; i++)cout << -n*a[i] << " ";
		cout << endl;
		cout << "2 " << n << endl;
		for(ll i = 1; i < n; i++)cout << (n-1)*a[i] << " ";
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
	}
	cout << endl;
	cin.get();
	return 0;
}

