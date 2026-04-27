#include <bits/stdc++.h>
using namespace std;
char arr[20];
int main() {
	for(int i=0; i<4; i++) {
        scanf("%s", arr+4*i);
	}
	int ans = 0;
	for(int i=0; i<16; i++) {
		if(isalpha(arr[i])) {
			ans += abs(i%4-(arr[i]-'A')%4)+abs(i/4-(arr[i]-'A')/4);
		}
	}
	cout << ans;
}