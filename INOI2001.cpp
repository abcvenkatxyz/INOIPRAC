#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define pb push_back
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
ll mx ,mn,size;
vi adj[100001]; vi ec,oc; ll ans = 0;
bool vis1[100001]; bool vis2[100001];

void dfs1(ll node){
	mx = max(mx,node); mn = min(mn,node);
	vis1[node] = true; size++;
	for (auto x : adj[node]){
		if (!vis1[x]){
			dfs1(x);
		}
	}
}

void dfs2(ll node, ll d){
	vis2[node] = true; ans += d;
	for (auto x : adj[node]){
		if (!vis2[x]){
			dfs2(x,d+1);
		}
	}
}

int main(){
    fastio;
	ll t; cin >> t;
	while(t--){
		ll n,m; cin >> n >> m; ec.clear(); oc.clear(); memset(vis1,false,sizeof vis1); memset(vis2, false, sizeof vis2);
		for (int i = 0; i < 100002; i++){
			adj[i].clear();
		}
		while(m--){
			ll u,v; cin >> u >> v; adj[u].pb(v); adj[v].pb(u);
		}
		for (ll i = 1; i <= n; i++){
			if (!vis1[i]){
				mx = 0; mn = 1e9; size = 0;
				dfs1(i);
				if (size % 2 == 0){
					ec.pb(mn);
				}
				else{
					oc.pb(mx);
				}
			}
			size = 0;
		}
		for (auto x : ec){
			dfs2(x,1);
		}
		cout << ans << " ";
		ans = 0;
		for (auto x : oc){
			dfs2(x,1);
		}
		cout << ans << endl;
		ans = 0;
	}
}
