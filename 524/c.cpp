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

ll n, m, x1, x2, y_1, y2, x3, x4, y3, y4, x5, y5, x6, y6;

void input(){
	cin >> n >> m >> x1 >> y_1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
}

void solve(){
	ll b = m*n/2, w = m*n/2 + (n%2 == m%2 and n%2 == 1);
	ll area = (x2 - x1 + 1) * (y2 - y_1 + 1);
	b -= area/2, w += area/2;
	if(x1%2 != y_1%2) b -= area%2, w += area%2;
	area = (x4 - x3 + 1) * (y4 - y3 + 1);
	w -= area/2, b += area/2;
	if(x3%2 == y3%2) b += area%2, w -= area%2;
	x5 = max(x1, x3), y5 = max(y_1, y3), x6 = min(x2, x4), y6 = min(y2, y4);
	if(x5 <= x6 and y5 <= y6){
		area = (x6 - x5 + 1) * (y6 - y5 + 1);
		w -= area/2, b += area/2;
		if(x5%2 != y5%2) b += area%2, w -= area%2;
	}
	cout << w << " " << b;
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
        cout<<endl;
	}
	cin.get();
	return 0;
}