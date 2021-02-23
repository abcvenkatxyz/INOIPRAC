/*
Venkatakrishnan Asuri
abcvenkatxyz
*/

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
#define s second
#define rep(i,a,b) for (ll i = a; i <= b; i++)
#define repn(i,a,b) for (ll i = a; i < b; i++)
#define urep(i,a,b) for (ull i = a; i <= b; i++)
#define urepn(i,a,b) for (ull i = a; i < b; i++)
#define maxx(a,b,c) max(max(a,b),c)
#define minn(a,b,c) min(min(a,b),c)
#define INF 1e9
#define MOD 1000000007
#define mod 20011
ll dp[305][305][305][2];
/*
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
*/

int main(){
	fastio;
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); 
	#endif
	ll r,c,d; cin >> r >> c >> d;
	ll g[r+1][c+1];
	rep(i,1,r){
		rep(j,1,c){
			cin >> g[i][j];
		}
	}
	rep(i,0,d){
		dp[r][c][i][0] = 1; dp[r][c][i][1] = 1;
	}
	for(ll i = r; i > 0; i--){
		for(ll j = c; j > 0; j--){
			if (i == r && j == c) continue;
			if (g[i][j]){
				dp[i][j][d][0] = dp[i][j][1][1];
				dp[i][j][d][1] = dp[i][j][1][0];
				rep(k,0,d){
					dp[i][j][k][0] = (dp[i+1][j][1][1] + dp[i][j+1][k+1][0]) % mod;
					dp[i][j][k][1] = (dp[i+1][j][k+1][1] + dp[i][j+1][1][0]) % mod;	
				}
			}
		}
	}
	cout << dp[1][1][0][0] << endl;
}

