#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ll n; cin >> n; vector<pair<ll,ll>> tri;
	for (ll i = 0; i < n; i++){
		ll a,b,c; cin >> a >> b >> c;
		tri.push_back({b+c,a});
	}
	sort(tri.begin(),tri.end(),greater<pair<ll,ll>>()); 	ll ans = 0; ll sum = 0;
	for (ll i = 0; i < n; i++){
		ans = max(ans, tri[i].first + tri[i].second + sum);	sum += tri[i].second;
	}
	cout << ans << endl; return 0;
}
