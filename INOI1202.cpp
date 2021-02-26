#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long int
#define vi vector<ll>
#define pii pair<ll,ll>
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define pb push_back
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
#define maxn 200005
/*
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
*/
ll a[maxn];

signed main(){
    ll n; cin >> n; 
    rep(i,1,n){ 
        cin >> a[i]; a[i] += i; a[i] = max(a[i],a[i-1]);

    }
    cout << a[n] << " "; ll cnt = 0;
    for(ll i = n; i > 1; i--){
        a[i] = a[i] - n; a[i] = max(a[i],a[i+1]) + 1; cnt++; a[i-1] += cnt;
        cout << max(a[i],a[i-1]) << " ";
    }
    cout << "\n";
}
