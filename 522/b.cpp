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

string s;

void input(){
	cin >> s;
}

void solve(){
	ll i = 20;
	for(ll t = 1; t <= 20; t++){
		if(sz(s)/20 + (sz(s)%20 != 0) == sz(s)/t + (sz(s)%t != 0)){
			i = t;
			break;
		}
	}
	
	ll x = sz(s)/i, y = sz(s)%i;
	if(!y){
		ll t = 0;
		cout << x << " " << i << endl;
		for(ll j = 0; j < sz(s); j++){
			cout << s[j];
			t++;
			if(t == i) {t = 0; cout << endl;}
		}
	}
	else{
		cout << x + 1 << " " << i << endl;
		y = i - y;
		ll ast = y / (x+1), astl = y % (x+1), t = 0;
		for(ll j = 0; j < sz(s); j++){
			cout << s[j];
			t++;
			if(t == i - ast - (astl != 0)) {
				for(ll o = 0; o < ast; o++)cout<<"*";
				if(astl){cout<<"*"; astl--;}
				t = 0; 
				cout << endl;
			}
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