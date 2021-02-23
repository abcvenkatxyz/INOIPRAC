#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long int
#define vi vector<ll>
#define pii pair<ll,ll>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_vack
#define mp make_pair
#define f first
#define Sec second
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repn(i,a,b) for (ll i = a; i < b; i++)
#define urep(i,a,b) for (ull i = a; i <= b; i++)
#define urepn(i,a,b) for (ull i = a; i < b; i++)
#define maxx(a,b,c) max(max(a,b),c)
#define minn(a,b,c) min(min(a,b),c)
#define INF 1e9
#define MOD 1000000007
/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
*/

ll cs(ll n){
	ll ans = 0;
	string p = to_string(n);
	repn(i,0,p.length()) {ans += p[i] - 48;} 
	return pow(ans,3);
}


int main(){
	fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	ll n,st; cin >> n >> st;
	vi e(n+1); rep(i,1,n) cin >> e[i];
	vi s(n+1); s[1] = st; rep(i,2,n) s[i] = s[i-1] + cs(s[i-1]);
	ll dp[n+1][n+1]; memset(dp,-INF,sizeof dp); dp[0][0] = 0;
	rep(i,1,n){
		rep(j,0,i){
			dp[i][j] = dp[i-1][j] + s[j] * e[i];
			if (j > 0){
				dp[i][j] = max(dp[i][j],dp[i-1][j-1]);
			}
		}
	}
	ll ans = 0;
	rep(i,1,n){
		ans = max(ans,dp[n][i]);
	}
	cout << ans;
}

