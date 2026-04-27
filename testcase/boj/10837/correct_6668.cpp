#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int k, c;
	cin >> k >> c;
	while(c--) {
		int m, n;
		cin >> m >> n;
		bool ok = true;
		if(m > n) {
			m--;
			int rm = k - m;
			if(n+rm < m) ok = false;
		} else if(m < n) {
			int rm = k - n;
			n--;
			if(m+rm < n) ok = false;
		}
		cout << (ok ? "1\n" : "0\n");
	}
}