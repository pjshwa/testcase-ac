#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <vector>
#include <cassert>

#define ll long long
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0; i<(n); i++)
#define set0(arr) memset(arr, 0, sizeof(arr))

using namespace std;
/*
This year in integer: k.
k/M = a ... x
k/N = b ... y
So k=aM+x=bN+y, while 0<=a<=lcf(M,N)/N, 0<=b<=lcf(M,N)/M
So aM+(x-y) has to be divisible to N.
------
12 10 1 1
1/12 = 0 ... 1
1/10 = 0 ... 1

*/
int main() {
	int T;
	cin >> T;
    assert(T <= 10000);
	while(T--) {
		int M,N,x,y;
		cin >> M >> N >> x >> y;
		if(x == M) x = 0;
		if(y == N) y = 0;
		int a = -1;
		for(int i=0;i<=N;i++) {
			if( i*M+x > 0 && !((i*M+x-y) % N) ) {
				a = i;
				break;
			}
		}
		if(a == -1){
			cout << "-1\n";
		} else {
			cout << (a*M+x) << '\n';
		}
	}
}