#include<bits/stdc++.h>
using namespace std;
#define max 1000002
 
vector<int> adj[max]; bool vis[max]; 
deque<int> q; int mus[max];
 
int dfs(int node){
    if (vis[node])
        return 0;
    vis[node] = true; int s = mus[node];
    for (auto ch : adj[node]){
        if (!vis[ch])
            s += dfs(ch);
    }
    return s;
}
 
int main(){
    int t; cin >> t;
    while(t--){
    	q.clear(); memset(vis,false,sizeof vis); memset(mus,0,sizeof mus);
		for (int i = 0; i < 1000003; i++){
			adj[i].clear();
		}
        int n,m,k; cin >> n >> m >> k;
        while(m--){
            int u,v; cin >> u >> v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        for (int i = 1; i <= n; i++){
            cin >> mus[i];
        }
        for (int i = 1; i <= n; i++){
            if (!vis[i]){
                q.push_back(dfs(i));
            }
        }
        if (k > q.size()){
            cout << -1 << endl;
        }
        else{
            int ans = 0;
            sort(q.rbegin(),q.rend());
            for (int i = 0; i < k; i++){
                if (i % 2 == 0){
                    int top = q.front(); q.pop_front(); ans += top;
                }
                else{
                    int bot = q.back(); q.pop_back(); ans += bot;
                }
            }
            cout << ans << endl;
        }
	
   }
    return 0;
}
 
/*
3
10 10 3
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
10 10 2
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
10 10 5
1 3
3 5
5 1
1 6
6 2
5 6
2 5
7 10
4 7
10 9
20 0 15 20 25 30 30 150 35 20
*/
