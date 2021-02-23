/*
Calvin's Game, INOI'13
We can move from the i-th position to (i+1) or (i+2) or (i-1) or (i-2)
Let us consider two DP states. We use 1-based indexing.
fwd[i] = max. sum possible if we start from i and end at N.
bck[i] = max. sum possible if we start from i and end at 1.

Backward Phase :
bck[1] = arr[1], bck[2] = arr[1] + arr[2]
for i = 3.....N :
	bck[i] = arr[i] + max(bck[i-1],bck[i-2])

Forward Phase :
for i = k+1.......N:
	fwd[i] = arr[i] + max(fwd[i-1],fwd[i-2])

Answer : 
For all i = k.....N:
	ans = max(ans,fwd[i]+bck[i]-arr[i])
*/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1000000007

ll arr[1000001];
ll fwd[1000001];
ll bck[1000001];

int main(){
	ll n,k; cin >> n >> k;
	for (int i = 1; i <= n; i++){
		cin >> arr[i];
	}
	for (int i = k+1; i <= n; i++){
		fwd[i] = arr[i] + max(fwd[i-1],fwd[i-2]);
	}
	bck[1] = arr[1], bck[2] = arr[1] + arr[2];
   	for (int i = 3; i <=n; i++){
		bck[i] = arr[i] + max(bck[i-1],bck[i-2]);
	}	
	ll ans = -INF;
	for (int i = k; i <= n; i++){
		ans = max(ans, bck[i] + fwd[i] - arr[i]);
	}
	cout << ans << endl;
	return 0;
}
