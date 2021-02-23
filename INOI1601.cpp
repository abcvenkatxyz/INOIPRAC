#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll a[100002]; vector<ll> adj[100002];
ll n,x,rt,ans = INT_MIN;

void dfs(ll root,ll mx){
	mx = max(a[root],mx); ans = max(ans,mx - a[root]);
	for (auto p : adj[root]){
		dfs(p,mx);
	}
}

int main(){
	cin >> n; 
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (ll i = 1; i <= n; i++){
		cin >> x; 
		if (x == -1) 
			rt = i;
		else
			adj[x].push_back(i);
	}
	dfs(rt,a[rt]); cout << ans << endl; return 0;
}

//4 5 10 6 12 2 -1 4 2
