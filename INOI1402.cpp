#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define pi pair<ll,ll>
#define INF 1000000000
vector<pi> adj[231];
ll c;

ll dijkstra(ll s){
	priority_queue <pi> q;
	bool vis[c+5]; fill(vis,vis+c+5,false);
	ll dist[c+5]; fill(dist,dist+c+5,INF);
	dist[s] = 0; q.push({0,s});
	while (!q.empty()){
		ll a = q.top().second; q.pop();
		if (vis[a]) continue;
		vis[a] = true;
		for (auto x : adj[a]){
			ll b = x.first; ll w = x.second;
			if (dist[a] + w < dist[b]){
				dist[b] = dist[a] + w;
				q.push({-dist[b],b});
			}
		}
	}
	ll maxcount = -INF;
	for (ll i = 1; i <= c; i++){
		if (dist[i] != INF){
			maxcount = max(maxcount,dist[i]);
		}
	}
	return maxcount;
}

int main(){
	ll f; cin >> c >> f;
	while (f--){
		ll a,b,w; cin >> a >> b >> w;
		adj[a].PB({b,w});
		adj[b].PB({a,w});
	}
	ll ans = -INF;
	for (ll i = 1; i <= c; i++){
		ans = max(ans,dijkstra(i));
	}
	cout << ans << endl;
	return 0;
	
}
