#include<bits/stdc++.h>
using namespace std;

const string dl = "\n";
const long long OO = 1e9;
const long long MOD = 1e9 + 7;
#define ll long long
#define ull long long
#define vec(type) vector<type>
#define vecv vector<vector<ll>>
#define mod(a,b) (a % b + b ) % b
#define cin(v) for(auto& x : v) cin >> x
#define cout(v) for(auto& x : v) cout << x << " "
#define of :
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define rv(exp) return void (cout << exp << dl)


void test_case() {
	
	/*
		
		
	
	*/
	int n;
	cin >> n;
	vec(ll) nums(n);cin(nums);
	ll res = 0;
	for(int bit =0;bit<30;bit++) {
		ll cnt = 0;
		for(int i = 0;i<n;i++){
			if(nums[i] &( 1 << bit)) cnt++;
			else res += ( 1ll << bit) * (cnt * (cnt+1)  / 2),cnt= 0;		
		}
		res += ( 1ll << bit) * (cnt * (cnt+1)  / 2),cnt= 0;
	}
	cout << res << dl;
}
int main() {
	 
	 ios_base::sync_with_stdio(false),cout.tie(0),cin.tie(0);	int tc= 1;	
	 
	 cin >> tc;
	
	 while(tc--) test_case();
	
	
}
