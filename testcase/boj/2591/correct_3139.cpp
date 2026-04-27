 #include <bits/stdc++.h>
#include <cstdio>
 using namespace std;
 #define ll long long
 ll dp[50];
 char arr[50];
 int n;
 int main() {
     ios::sync_with_stdio(0);cin.tie(0);
     scanf("%49s", arr+1);
     n = strlen(arr+1);
     dp[0] = dp[1] = 1;
     for(int i=2; i<=n; i++) {
         if(arr[i] != '0')
             dp[i] = dp[i-1];
         if((arr[i-1] == '1' || arr[i-1] == '2' ) || (arr[i-1] == '3' && arr[i] <= '4'))
             dp[i] += dp[i-2];
     }
     cout << dp[n];
 }
