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

string a, b;

bool check(char ch){
	return ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u';
}

void input(){
	cin >> a >> b;
}

void solve(){
	if(sz(a) != sz(b))cout<<"No";
	else{
		bool f = true;
		for(ll i = 0; i < sz(a); i++){
			if(a[i] == b[i])continue;
			if((check(a[i]) and !check(b[i])) or (!check(a[i]) and check(b[i])))f = false;
		}
		if(f)cout<<"Yes";
		else cout<<"No";
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