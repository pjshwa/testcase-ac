#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

#define MOD 1000000007
#define int long long
#define rep(i, n) for(int i=0;i<(n);i++)
#define set0(arr) memset(arr, 0, sizeof(arr))
#define sz(x) (int)(x).size()

using namespace std;

int32_t main() {
	int n, k;
	cin >> n >> k;
	int dp[k+1], lastdp[k+1]; set0(dp); set0(lastdp); // dp[i] at jth iter = ways to build value i using only first (j+1) kind of coin.
	int value[n];
	rep(i, n) cin >> value[i];
	sort(value, value+n);
	for(int i=value[0]; i<=k; i+=value[0]) {
		lastdp[i] = 1;
	}
	for(int j=1; j<n; j++) { // jth coin
		for(int i=value[j]; i<=k; i+=value[j]) { // using the coin for value i
			dp[i] += 1;
			for(int x=1; x+i<=k; x++) {  // added with previous value x
				dp[x+i] += lastdp[x];
			}
		}
		for(int i=1; i<=k; i++) {
			dp[i] += lastdp[i];
		}
		memcpy(lastdp, dp, sizeof(dp));
		set0(dp);
	}
	cout << lastdp[k];

}