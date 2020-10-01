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
priority_queue<pll> pq;
ll b[25][25] = {0};

void input(){
	cin >> n;
}

void put(vector<pll> pos){
	pll v = pq.top();
	pq.pop();
	if(v.f < sz(pos)){
		cout<<"NO";
		exit(0);
	}
	for(auto it:pos)b[it.f][it.s] = v.s;
	v.f -= sz(pos);
	pq.push(v);
}

ll rev(ll x){
	return n - x - 1;
}

void solve(){
	vll a(n*n);
	for(auto &it:a)cin >> it;  
	for(auto it:a)mp[it]++;
	for(auto it:mp)pq.push({it.s, it.f});
	for(ll i = 0; i < n/2; i++) for(ll j = 0; j < n/2; j++) put({{i, j}, {i, rev(j)}, {rev(i), j}, {rev(i), rev(j)}});
	if(n%2){
		for(ll i = 0; i < n/2; i++){
			put({{i, n/2}, {rev(i), n/2}});
			put({{n/2, i}, {n/2, rev(i)}});
		}
		put({{n/2, n/2}});
	}
	cout << "YES\n";
	for(ll i = 0; i < n; i++){for(ll j = 0; j < n; j++) cout << b[i][j] << " "; cout << endl;}
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