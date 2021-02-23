#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll t; cin >> t;
	while(t--){
		ll n,k; cin >> k >> n;
		if (k == 1){
			if (n % 3 == 0)
				cout << 1 << endl;
			else
				cout << 0 << endl;
		}
		else if (k == 2){
			ll dp[n+1]; dp[0] = 1; dp[1] = 0; dp[2] = 1; dp[3] = 1;
			for (ll i = 4; i <= n; i++){
				dp[i] = (dp[i-2] + dp[i-3]) % MOD;
			}
			cout << dp[n] << endl;
		}
		else{
			ll a[n+1],b[n+1],c[n+1];
			a[0] = 1; a[1] = 1; a[2] = 1;
			b[0] = 0; b[1] = 0; b[2] = 0;
			c[0] = 0; c[1] = 0; c[2] = 1;
			for (ll i = 3; i <= n; i++){
				a[i] = (a[i-1] +a[i-3] + 2 * b[i-2]) % MOD;
				b[i] = (b[i-3] + c[i-2]) % MOD;
				c[i] = (a[i-2] + c[i-3]) % MOD;
			}
			cout << a[n] << endl;
		}
	}
	return 0;
}
